/*
 * vanilla.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#include "Vanilla.h"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_) :
	ThePayOff(ThePayOff_), Expiry(Expiry_)
{}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return ThePayOff(Spot);
}


/*// the rule of three  (not these are moved to Bridge)
VanillaOption::VanillaOption(const VanillaOption& original)
{
	Expiry = original.Expiry;
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original)
{
	if (this != &original)
	{
		Expiry = original.Expiry;
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;
}

VanillaOption::~VanillaOption()
{
	delete ThePayOffPtr;
}
*/

