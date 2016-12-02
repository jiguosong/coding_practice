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

	return 0;
}


