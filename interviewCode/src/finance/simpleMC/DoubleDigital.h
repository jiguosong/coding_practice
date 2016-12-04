/*
 * DoubleDigital.h
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#ifndef DOUBLEDIGITAL_H_
#define DOUBLEDIGITAL_H_

#include "PayOff.h"

class PayOffDoubleDigital: public PayOff
{
public:
	PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffDoubleDigital() {};
	virtual PayOff *clone() const;
private:
	double LowerLevel;
	double UpperLevel;
};

#endif /* DOUBLEDIGITAL_H_ */
