/*
 * PayOffBridge.h
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#ifndef PAYOFFBRIDGE_H_
#define PAYOFFBRIDGE_H_

#include "PayOff.h"

class PayOffBridge
{
public:
	PayOffBridge(const PayOffBridge& original);
	PayOffBridge(const PayOff& innerPayOff);
	inline double operator()(double Spot) const;
	~PayOffBridge();
	PayOffBridge& operator=(const PayOffBridge& original);
private:
	PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const
{
	return ThePayOffPtr->operator ()(Spot);
}

#endif /* PAYOFFBRIDGE_H_ */
