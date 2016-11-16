/*
 * Counter.h
 *
 *  Created on: Nov 15, 2016
 *      Author: songjiguo
 */

#ifndef COUNTER_H_
#define COUNTER_H_

class Counter {
private:
      int mCounter;
public:
      Counter() : mCounter(0) {}
      int Increment();
};

#endif /* COUNTER_H_ */
