/*
 * ParkMiller.h
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#ifndef PARKMILLER_H_
#define PARKMILLER_H_

#include "random2.h"

class ParkMiller
{
public:
	ParkMiller(long Seed = 1);
	long GetOneRandomInteger();
	void SetSeed(long Seed);
	static unsigned long Max();
	static unsigned long Min();
private:
	long Seed;
};
class RandomParkMiller: public RandomBase
{
public:
	RandomParkMiller(unsigned long Dimensionality, unsigned long Seed = 1);

	virtual RandomBase* clone() const;
	virtual void GetUniforms(JSArray& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void Reset();

	virtual void ResetDimensionality(unsigned long NewDimensionality);
private:
	ParkMiller InnerGenerator;
	unsigned long InitialSeed;
	double Reciprocal;  // the reciprocal of the maximum value plus one
};

#endif /* PARKMILLER_H_ */
