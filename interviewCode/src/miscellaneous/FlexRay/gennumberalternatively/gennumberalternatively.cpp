/*
 * gennumberalternatively.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: songjiguo
 */

/*Given 2 numbers A and B ex: 123 and 678, produce an integer C (162738) by taking digits
alternatively from A and B. If one integer is longer than the other, the remaining digits
of the longer one should be appended to the result. Also, return -1 if the resultant
number exceeds 100000000.

Examples: A=123 B=67894, then C = 16273894
          A=12345 B=87 , then C = 1827345
          A=1234  B=0  , then C = 10234 */

#include "gennumberalternatively.h"

#include <algorithm>
#include <vector>
using std::vector;

#include <iostream>
using namespace std;

int gennumberalternatively::produceNumber(int num1, int num2)
{
	vector<int> t1;
	int tmp = num1;
	while(tmp) {
		t1.push_back(tmp%10);
		tmp = tmp/10;
	}

	vector<int> t2;
	tmp = num2;
	if(tmp == 0) t2.push_back(tmp);
	while(tmp) {
		t2.push_back(tmp%10);
		tmp = tmp/10;
	}

	std::reverse(t1.begin(), t1.end());
	std::reverse(t2.begin(), t2.end());
	int sz1 = t1.size();
	int sz2 = t2.size();
	int sz = std::min(sz1, sz2);

	int res = 0;
	for(int i = 0; i < sz; i++) {
		res = res*10 + t1[i];
		res = res*10 + t2[i];
	}

	if(sz < sz1) {
		for(int i = sz; i < sz1; i++) res = res*10 + t1[i];
	} else if (sz < sz2) {
		for(int i = sz; i < sz2; i++) res = res*10 + t2[i];
	}

	return res;
}

