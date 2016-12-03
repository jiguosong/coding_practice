/*
 * isswapsorted.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: songjiguo
 */

#include "isswapsorted.h"

// assume increasing sorted
/*Given an array of integers. Is it possible to sort the array by swapping two numbers?
 * Return a boolean value.*/

bool isswapsorted::isSwaptwoSorted(vector<int> &nums)
{
	int count = 0;

	for(int i = 0; i < nums.size() - 1; i++) {
		if(nums[i] > nums[i+1]) count++;
	}
	return count == 2;
}
