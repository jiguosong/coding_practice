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

	T &operator=(const T &other) {};

private:
	int a;
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

	return 0;
}


