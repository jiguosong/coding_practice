/*
 * buildfortress.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: songjiguo
 */

/*
Given an array of heights (A = {1,1,2,2,2,3,1,1,3,3,3}).
A king wants to build fortresses in all the hills and all the valleys.
A hill is a height which is higher than any heights around,
and a valley is lower than any surrounding heights.
Return how many fortresses need to be built.

Solution must run in O(N)
worst case space O(1)
input array can be modified.

*/

#include "buildfortress.h"

#include <iostream>
using namespace std;

int buildfortress::numberofFortresstoBuild(vector<int> &numbers)
{
	if(numbers.empty()) return 0;


/*    can not use this since space O(1)
	vector<int> tmp;
	int pre = numbers[0];
	tmp.push_back(pre);
	for(int e:numbers) {
		if(e != pre) tmp.push_back(e);
		pre = e;
	}

	int count = 0;
	for(int i = 1; i < tmp.size()-1; i++) {
		if(tmp[i] > tmp[i-1] && tmp[i] < tmp[i+1]) count++;
		if(tmp[i] < tmp[i-1] && tmp[i] < tmp[i+1]) count++;
	}
*/

	int count = 0;
	int left, right, middle;
	left = right = middle = 0;
	for(int i = 0; i < numbers.size(); i++) {
		while(numbers[left] == numbers[middle]) ++middle;
		if(middle >= numbers.size()) break;

		right = middle;
		while(numbers[middle] == numbers[right]) ++right;

		if(right >= numbers.size()) break;
		if(numbers[middle] > numbers[left] && numbers[middle] > numbers[right]) count++;
		if(numbers[middle] < numbers[left] && numbers[middle] < numbers[right]) count++;

		left = middle;
		middle = right;
	}
	return count;
}


