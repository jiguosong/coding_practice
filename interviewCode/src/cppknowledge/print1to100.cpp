/*
 * print1to100.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: songjiguo
 */

#include <iostream>

using namespace std;

// method 1
template<int N>
struct PrintN {
	static void print() {
		PrintN<N - 1>::print();
		cout << N << endl;
	}
};

template<>
struct PrintN<1> {
	static void print() {
		cout << 1 << endl;
	}
};

// method 2
class A {
public:
	static int a;
	A() {
		cout << a++ << endl;
	}
};

int A::a = 1;

int main() {
	const int N = 100;
	PrintN<N>::print();

	A aaa[N];
}

