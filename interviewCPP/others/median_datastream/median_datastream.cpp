/*
 * median_datastream.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "median_datastream.h"

/*
Median is the middle value in an ordered integer list. If the size of the list is
even, there is no middle value. So the median is the mean of the two middle value.
*/

double median_datastream::findMedian()
{
	double res = 0;

	if(left_heap.size() > right_heap.size()) res = left_heap.top();
	/*	Since by default, the heap is max_heap, so we save the negative in the right_heap*/
	else res = double(left_heap.top() - right_heap.top())/2;
	return res;
}

void median_datastream::addNum(int num)
{
	left_heap.push(num);
	right_heap.push(-left_heap.top());
	left_heap.pop();

	if(right_heap.size() > left_heap.size()) {
		left_heap.push(-right_heap.top());
		right_heap.pop();
	}
}
