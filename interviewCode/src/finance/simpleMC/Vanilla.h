/*
 * vanilla.h
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#ifndef VANILLA_H_
#define VANILLA_H_

//#include "PayOff.h"
#include "PayOffBridge.h"

class VanillaOption
{
public:
	//VanillaOption(const PayOff& ThePayOff_, double Expiry_);
	VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);

	// the rule of three  (not these are moved to Bridge)
	//VanillaOption(const VanillaOption& original);
	//VanillaOption& operator=(const VanillaOption& original);
	//~VanillaOption();

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;
private:
	double Expiry;
	//PayOff* ThePayOffPtr;
	PayOffBridge ThePayOff;
};

#endif /* VANILLA_H_ */
