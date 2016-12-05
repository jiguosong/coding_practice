/*
 * Task1.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "Task1.h"
#include <algorithm>
#include <iostream>
using namespace std;

int Task1::solution(vector<int> &A) {
	if(A.empty()) return -1;

	int sz = A.size();

	// to handle overflow, there are 2 approaches (not mention safeint and x86 instruction)
	// 1) use long long
/*	long long left = 0;
	long long right = 0;
	for(int e : A) right += static_cast<long long> (e);*/

	// 2) return the error
	int left = 0;
	int right = 0;
	for(int e : A) {
		if(right > 0 && e > std::numeric_limits<int>::max() - right) {
			cerr << "overflow, return -1" << endl;
			return -1;
		} else if(right < 0 && e < std::numeric_limits<int>::min() - right) {
			cerr << "underflow, return -1" << endl;
			return -1;
		} else {
			right += e;
		}
	}

	for(int i = 0; i < sz; ++i) {
		right -= A[i];
		if(right == left) return i;
		left += A[i];
	}

	return -1;
}
