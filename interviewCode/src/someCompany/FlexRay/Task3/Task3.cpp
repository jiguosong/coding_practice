/*
 * Task1.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "Task3.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
25 = 1 + 3 + 5 + 7 + 9
36 = 1 + 3 + 5 + 7 + 9 + 11
....
1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n
*/

int Task3::solution(int A, int B) {
	if(B < 0 || A > B) return 0;

	int i = 1;
	int tmp = B;
	while(tmp > 0) {
		tmp -= i;
		i += 2;    // odd numbers
	}
	i = i - 2;     // compensate the last loop

	int k = 0;
	if(tmp != 0) {
		k = static_cast<int>(std::sqrt(B));
		B = k*k;   // get the closest complete square number
		i = i - 2;
	}

	int count = 0;
	if (tmp == 0 || B > A) count = 1;
	int t = A < 0 ? 0:A;

	while(B > t) {
		B -= i;
		i -= 2;
		++count;
	}

	return count;

}
