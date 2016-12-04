/*
 * random2.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#include "random2.h"
#include "Normals.h"
#include <cstdlib>

using namespace std;

void RandomBase::GetGaussians(JSArray& variates)
{
	GetUniforms(variates);
	for (unsigned long i = 0; i < Dimensionality; i++)
	{
		double x = variates[i];
		variates[i] = InverseCumulativeNormal(x);
	}
}
void RandomBase::ResetDimensionality(unsigned long NewDimensionality)
{
	Dimensionality = NewDimensionality;
}
RandomBase::RandomBase(unsigned long Dimensionality_) :
		Dimensionality(Dimensionality_)
{
}

