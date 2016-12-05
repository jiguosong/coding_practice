/*
 * containsKnumbers.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: songjiguo
 */

/*Given a non-empty zero-indexed array A of N integers (sorted in  non-decreasing order)
and integer K, checks whether A contains numbers 1,2,..., K (every number from 1 to K
at least once) and no other numbers.
Example 1: A = [1,1,2,3,3], K = 3. The function should return true
Example 2: A = [1,1,3], K = 2. Return should be false.*/

#include "containsKnumbers.h"

#include <iostream>
#include <cassert>

using namespace std;

bool containsKnumbers::isContainsAllKNumbers(vector<int> &nums, int K)
{
	if(nums.size() < K) return false;

	for(int val = 1; val <= K; ++val) {
		int left = 0;
		int right = nums.size()-1;
		bool found = false;
		while(left < right) {
			int mid = left + (right-left)/2;
			if(nums[mid] < val) left = mid+1;
			else if(nums[mid] > val) right = mid-1;
			else {
				found = true;
				break;
			}
		}
		if(!found) return false;
	}

	return true;
}


bool containsKnumbers::solution(vector<int> &A, int K) {
	int n = A.size();
	for (int i = 0; i < n - 1; ++i) {
		if (A.at(i) + 1 < A.at(i+1))
			return false;
	}
	if (A[0] != 1 || A[n - 1] != K)     // change to OR   ????? who said two ends must be 1 and K???
		return false;    else
		return true;
}

/*
The code gives right answer to the example cases, but there's a bug in it. Fix the code by modifying at most 2 lines.
bool solution(vector<int> &A, int K) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        if (A[i] + 1 < A[i + 1])
            return false;
    }
    if (A[0] != 1 && A[n - 1] != K)
        return false;    else
        return true;
}*/
