/*
 * moveconstructor_test.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

/*
default assignment operator performs memberwise assignment from the members of a
to the members of b, which for pointers (a.data and b.data) is just a bitwise copy
*/

/*nonvirtual functions like B::mf and D::mf are statically bound*/

/*static class members should never be initialized in a class's constructor. That means that because
 pB is declared to be of type pointer-to-B, nonvirtual functions invoked through pB will always be those
 defined for class B, even if pB points to an object of a class derived from B, Virtual functions, on the other hand,
 are dynamically bound, so they don't suffer from this problem. If mf were a virtual function,
 a call to mf through either pB or pD would result in an invocation of D::mf, because what pB and pD really point to
 is an object of type D. */

/*An object's dynamic type is determined by the type of the object to which it currently refers*/

/*
cast from a base class pointer to a derived class pointer is called a downcast,
because you're casting down the inheritance hierarchy
*/

/*When you try to delete a derived class object through a base class pointer and the
base class has a nonvirtual destructor (as EnemyTarget does), the results are undefined.*/
// declare a virtual destructor in a class if and only if that class contains at least one virtual function.

/*Bjarne Stroustrup, the designer of C++, went to a lot of trouble to ensure that user-defined types would
mimic the built-in types as closely as possible. That's why you can overload operators, write type conversion
functions , take control of assignment and copy construction, etc. */

/*object identity*/

/*Virtual functions are typically implemented by adding a pointer (the “vptr”) to each object
of a class with virtual functions. This pointer points to the appropriate table of functions
(the “vtbl”). Each class has its own vtbl shared by all objects of that class.*/

/* Private inheritance means is-implemented-in-terms-of. If you make a class D privately inherit from a class B,
 you do so because you are interested in taking advantage of some of the code that has already been written for
 class B, not because there is any conceptual relationship between objects of type B and objects of type D.
 As such, private inheritance is purely an implementation technique. Using the terms introduced in Item 36,
 private inheritance means that implementation only should be inherited; interface should be ignored.
 If D privately inherits from B, it means that D objects are implemented in terms of B objects, nothing more.
 Private inheritance means nothing during software design, only during software implementation. */

/*
Bear in mind that the inline directive, like register, is a hint to compilers, not a command. That means compilers
are free to ignore your inline directives whenever they want to, and it's not that hard to make them want to.
For example, most compilers refuse to inline "complicated" functions (e.g., those that contain loops or are recursive),
and all but the most trivial virtual function calls stop inlining routines dead in their tracks. (This shouldn't be much
of a surprise. virtual means "wait until runtime to figure out which function to call," and inline means "during "
"compilation, replace the call site with the called function." If compilers don't know which function will
be called, you can hardly blame them for refusing to make an inline call to it.) It all adds up to this:
whether a given inline function is actually inlined is dependent on the implementation of the compiler you're using.
*/

/*Note that the generated destructor is nonvirtual unless it's for a class inheriting from a base class that
itself declares a virtual destructor. */

/*As for the copy constructor and the assignment operator, the official rule is this: the default copy constructor
(assignment operator) performs memberwise copy construction (assignment) of the nonstatic data members of the class.
That is, if m is a nonstatic data member of type T in a class C and C declares no copy constructor (assignment operator),
m will be copy constructed (assigned) using the copy constructor (assignment operator) defined for T, if there is one.
If there isn't, this rule will be recursively applied to m's data members until a copy constructor (assignment operator)
or built-in type (e.g., int, double, pointer, etc.) is found. By default, objects of built-in types are copy constructed (assigned)
using bitwise copy from the source object to the destination object. For classes that inherit from other classes,
this rule is applied to each level of the inheritance hierarchy, so user-defined copy constructors and assignment
operators are called at whatever level they are declared. */

#include <iostream>
#include <utility>

template<typename T>
class uniq_ptr {
	T *ptr;
public:
	T &operator*(){
		return *ptr;
	}

	T *operator->(){
		return ptr;
	}

	explicit uniq_ptr(T *p = nullptr) {
		ptr = p;
	}

	// destructor
	~uniq_ptr() {
		delete ptr;
	}

	// move constructor
	uniq_ptr(uniq_ptr &&source) {
		ptr = source.ptr;
		source.ptr = nullptr;
	}

	// move assignment operator
/*	uniq_ptr &operator=(uniq_ptr &&source) {
		if(this != &source) {
			delete ptr;
			ptr = source.ptr;
			source.ptr = nullptr;
		}
		return *this;
	}*/

	// the copy-and-swap idiom
	uniq_ptr& operator=(uniq_ptr source)   // note the missing reference
	{
		std::swap(ptr, source.ptr);
		return *this;
	}

};

class A {
	int a;
public:
	A(int x) : a(x){std::cout << x << std::endl;};
	A(){a = 0;};
	~A(){};
};

A* make_something()
{
    return new A();
}

int main()
{
	A *test = new A(10);
	A test2(1);

	A test3 = 55;

	uniq_ptr<A> a(new A);
	//uniq_ptr<A> b(a);             // do not allow the implicit and dangerous move
	uniq_ptr<A> c(make_something());

	//uniq_ptr<A> e = c;
/*	Sometimes, we want to move from lvalues. That is, sometimes we want the compiler to treat an lvalue as if
	it were an rvalue, so it can invoke the move constructor, even though it could be potentially unsafe. For
	this purpose, C++11 offers a standard library function template called std::move inside the header <utility>.
	This name is a bit unfortunate, because std::move simply casts an lvalue to an rvalue; it does not move
	anything by itself. It merely enables moving.*/
	uniq_ptr<A> f = std::move(a);   // explicit move

}

