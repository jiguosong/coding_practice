/*
 * Arrays.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#include "Arrays.h"
#include <algorithm>
#include <numeric>

JSArray::JSArray(unsigned long size) :
		Size(size), Capacity(size)
{
	if (Size > 0)
	{
		ValuesPtr = new double[size];
		EndPtr = ValuesPtr;
		EndPtr += size;
	}
	else
	{
		ValuesPtr = 0;
		EndPtr = 0;
	}
}

JSArray::JSArray(const JSArray& original) :
		Size(original.Size), Capacity(original.Size)
{
	if (Size > 0)
	{
		ValuesPtr = new double[Size];
		EndPtr = ValuesPtr;
		EndPtr += Size;
		std::copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
	}
	else
	{
		ValuesPtr = EndPtr = 0;
	}
}

JSArray::~JSArray()
{
	if (ValuesPtr > 0)
		delete[] ValuesPtr;
}

JSArray& JSArray::operator=(const JSArray& original)
{
	if (&original == this)
		return *this;
	if (original.Size > Capacity)
	{
		if (Capacity > 0)
			delete[] ValuesPtr;
		ValuesPtr = new double[original.Size];
		Capacity = original.Size;
	}
	Size = original.Size;
	EndPtr = ValuesPtr;
	EndPtr += Size;
	std::copy(original.ValuesPtr, original.EndPtr, ValuesPtr);
	return *this;
}
void JSArray::resize(unsigned long newSize)
{
	if (newSize > Capacity)

	{
		if (Capacity > 0)
			delete[] ValuesPtr;
		ValuesPtr = new double[newSize];
		Capacity = newSize;
	}
	Size = newSize;
	EndPtr = ValuesPtr + Size;
}

JSArray& JSArray::operator+=(const JSArray& operand)
{
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply += two arrays must be of same size");
	}
#endif
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] += operand[i];
	return *this;
}

JSArray& JSArray::operator-=(const JSArray& operand)
{
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply -= two arrays must be of same size");
	}
#endif
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] -= operand[i];
	return *this;
}

JSArray& JSArray::operator/=(const JSArray& operand)
{
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply /= two arrays must be of same size");
	}
#endif
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] /= operand[i];
	return *this;
}

JSArray& JSArray::operator*=(const JSArray& operand)
{
#ifdef RANGE_CHECKING
	if ( Size != operand.size())
	{
		throw("to apply *= two arrays must be of same size");
	}
#endif
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] *= operand[i];
	return *this;
}

/////////////////////////////
JSArray& JSArray::operator+=(const double& operand)
{
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] += operand;
	return *this;
}

JSArray& JSArray::operator-=(const double& operand)

{
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] -= operand;
	return *this;
}

JSArray& JSArray::operator/=(const double& operand)
{
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] /= operand;
	return *this;
}

JSArray& JSArray::operator*=(const double& operand)
{
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] *= operand;
	return *this;
}

JSArray& JSArray::operator=(const double& val)
{
	for (unsigned long i = 0; i < Size; i++)
		ValuesPtr[i] = val;
	return *this;
}

double JSArray::sum() const
{
	return std::accumulate(ValuesPtr, EndPtr, 0.0);
}

double JSArray::min() const
{
#ifdef RANGE_CHECKING
	if ( Size==0) {	}

	throw("cannot take min of empty array");
}
#endif
	double* tmp = ValuesPtr;
	double* endTmp = EndPtr;
	return *std::min_element(tmp, endTmp);
}

double JSArray::max() const
{
#ifdef RANGE_CHECKING
	if ( Size==0)
	{
		throw("cannot take max of empty array");
	}
#endif
	double* tmp = ValuesPtr;
	double* endTmp = EndPtr;
	return *std::max_element(tmp, endTmp);
}

JSArray JSArray::apply(double f(double)) const
{
	JSArray result(size());
	std::transform(ValuesPtr, EndPtr, result.ValuesPtr, f);
	return result;
}
