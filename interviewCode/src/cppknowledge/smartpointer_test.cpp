/*
 * smartpointer.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <memory>
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

class T {
public:
	void SomeFunc(){};

	T &operator=(const T &other){};

private:
	int a;
};


// implement a smart pointer-lie reference counting

class KevinPtr;

class Kevin {
public:
	Kevin() : count_(0) {};
	int getCount() {return count_;};
private:
	friend class KevinPtr;
	int count_;
};

class KevinPtr {
public:
	Kevin *operator-> () {return p_;};
	Kevin operator* () {return *p_;};

	KevinPtr(Kevin *p): p_(p) {++p_->count_;};
	~KevinPtr() {if(--p_->count_ == 0) delete p_;}
	KevinPtr(const KevinPtr &p): p_(p.p_) {++p_->count_;};
	KevinPtr& operator= (const KevinPtr &p) {
		Kevin* const old = p_;
		p_ = p.p_;
		++p_->count_;
		if(--old->count_ == 0) delete old;
		return *this;
	}

private:
	Kevin *p_;
};


class X
{
};

int main() {
	T* pt1 = new T;
	// right now, we own the allocated object

	// pass ownership to an auto_ptr
	std::unique_ptr<T> pt2( pt1 );

	// use the auto_ptr the same way
	// we'd use a simple pointer
	//pt2->SomeFunc(); // same as "pt1->SomeFunc();"

	// use get() to see the pointer value
	//assert( pt1 == pt2.get() );

	// use release() to take back ownership
	//T* pt3 = pt2.release();

	// delete the object ourselves, since now
	// no auto_ptr owns it any more
	//delete pt3;

	Kevin *old = new Kevin();         // by default, there is no smart pointer
	KevinPtr *p1 = new KevinPtr(old); // init to 0 and increase
	KevinPtr *p2 = new KevinPtr(old);

	cout << old->getCount() << endl;
	delete p1;
	cout << old->getCount() << endl;
	delete p2;


/*	The C++ Standard says that an STL element must be "copy-constructible"
	and "assignable." In other words, an element must be able to be assigned
	or copied and the two elements are logically independent.
	std::auto_ptr does not fulfill this requirement.*/
	// http://ootips.org/yonat/4dev/smart-pointers.html
	std::vector<std::auto_ptr<X> > vecX;
	// vecX.push_back(new X);  -? wrong

	std::auto_ptr<X> pX = vecX[0];  // vecX[0] is assigned NULL.

	return 0;
}



