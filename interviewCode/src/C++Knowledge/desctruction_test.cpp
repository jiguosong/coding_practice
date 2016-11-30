/*
 * desctruction_test.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */


#include <iostream>
using namespace std;

static int cnt = 0;

class Base {
    virtual void method() {std::cout << "from Base cnt " << cnt++ << std::endl;}
public:
    virtual ~Base() {method();}
    void baseMethod() {method();}
};

class A : public Base {
    void method() {std::cout << "from A cnt " << cnt++ << std::endl;}
public:
    ~A() {method();}
};

int main(void) {
    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}


