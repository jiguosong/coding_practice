/*
 * AntiThetic.h
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#ifndef ANTITHETIC_H_
#define ANTITHETIC_H_

#include "random2.h"
#include "Wrapper.h"

// adaptor pattern again
class AntiThetic: public RandomBase
{
public:
	AntiThetic(const Wrapper<RandomBase>& innerGenerator);
	virtual RandomBase* clone() const;
	virtual void GetUniforms(JSArray& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void ResetDimensionality(unsigned long NewDimensionality);
	virtual void Reset();
private:
	Wrapper<RandomBase> InnerGenerator;
	bool OddEven;
	JSArray NextVariates;
};

#endif /* ANTITHETIC_H_ */
