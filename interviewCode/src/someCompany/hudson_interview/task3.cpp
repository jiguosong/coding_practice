/*
 * task3.cpp
 *
 *  Created on: Nov 12, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

#include <vector>
#include <limits>

using namespace std;

int solution(vector<int> &A) {

	int res = numeric_limits<int>::min();  //
	int sz = A.size();

	if(sz == 1) return A[0];  // fuck!!!!! I missed this!!!!

	vector<int> max_from_left(sz, 0);  // contains the max value so far from left side, inclusively
	vector<int> max_from_right(sz, 0); // contains the max value so far from right side, exclusicely
	max_from_left[0] = A[0];           // initialize left[0]
	max_from_right[sz-1] = A[sz-1];    // initialize right[0]
	max_from_right[sz-2] = A[sz-1];

	// from left
	for(int i = 1; i < sz; ++i) {
		max_from_left[i] = max(A[i], max_from_left[i-1]);
	}

	// from right

	for(int i = sz-3; i >= 0; --i) {
		max_from_right[i] = max(A[i+1], max_from_left[i+2]);
	}

	// do the actual computation
	for(int i = 0; i < sz; ++i) {
		res = max(res, abs(max_from_right[i]-max_from_left[i]));
	}

	return res;

}


int main()
{
	cout << "Hudson task 3 testing....\n";

	//vector<int> A = {4,3,2,5,1,1};
	//vector<int> A = {1,3,-3};
	vector<int> A = {1};
	int ans = solution(A);
	cout << ans;
}
