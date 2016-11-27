/*
 * median_datastream.h
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#ifndef MEDIAN_DATASTREAM_H_
#define MEDIAN_DATASTREAM_H_

#include <queue>
using std::priority_queue;

class median_datastream {
public:
	double findMedian();
	void addNum(int num);
private:
	priority_queue<int> left_heap, right_heap;
};

#endif /* MEDIAN_DATASTREAM_H_ */
