/*
 * random2.h
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#ifndef RANDOM2_H_
#define RANDOM2_H_

#include "Arrays.h"

class RandomBase
{
public:
	RandomBase(unsigned long Dimensionality);
	inline unsigned long GetDimensionality() const;
	virtual RandomBase* clone() const=0;
	virtual void GetUniforms(JSArray& variates)=0;
	virtual void Skip(unsigned long numberOfPaths)=0;
	virtual void SetSeed(unsigned long Seed) =0;
	virtual void Reset()=0;

	virtual void GetGaussians(JSArray& variates);
	virtual void ResetDimensionality(unsigned long NewDimensionality);

	virtual ~RandomBase(){};  // better have one here
private:
	unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const
{
	return Dimensionality;
}

#endif /* RANDOM2_H_ */
