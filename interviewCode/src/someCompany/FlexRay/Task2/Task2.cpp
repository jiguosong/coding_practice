/*
 * Task1.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "Task2.h"
#include <iostream>
#include <limits>
using namespace std;


// 0 <= K < N-1
int Task2::solution(vector<int> &A)
{
	int sz = A.size();
	vector<int> left_max(sz, 0);
	vector<int> right_max(sz, 0);

	left_max[0] = A[0];
	right_max[sz-1] = A[sz-1];

	for(int i = 1; i < sz; ++i) left_max[i] = std::max(left_max[i-1], A[i]);   // inclusive
	for(int i = sz-2; i >= 0; --i) right_max[i] = std::max(right_max[i+1], A[i+1]);  // exclusive

	//int max = std::numeric_limits<int>::min();
	int max = 0;  // notice that we use abs here
	for(int i = 0; i < sz; ++i) {
		max = std::max(max, std::abs(left_max[i] - right_max[i]));    // normal
	}

	return max;

}



/*    if A's range is too large. But now it is between -10^9 and 10^9
	for(int i = 0; i < sz; ++i) {
		if(right_max[i] < 0 && left_max[i] > std::numeric_limits<int>::max() + right_max[i]) {
			cerr << "overflow, return -1" << endl;
					return -1;
		} else if(right_max[i] > 0 && left_max[i] < std::numeric_limits<int>::min() + right_max[i]) {
			cerr << "underflow, return -1" << endl;
					return -1;
		} else {
			max = std::max(max, std::abs(left_max[i] - right_max[i]));    // normal
		}
	}
*/
