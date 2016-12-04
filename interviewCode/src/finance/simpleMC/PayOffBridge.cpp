/*
 * PayOffBridge.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#include "PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
	ThePayOffPtr = innerPayOff.clone();
}

PayOffBridge::~PayOffBridge()
{
	delete ThePayOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
	if (this != &original) {
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;
}
