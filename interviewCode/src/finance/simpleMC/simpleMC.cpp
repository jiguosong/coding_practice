/*
 * simpleMC.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <cmath>
#include "random1.h"
#include "simpleMC.h"

using namespace std;

double testest::SimpleMonteCarlo(const VanillaOption& TheOption, double Spot, const Parameters& Vol,
						            const Parameters& r, unsigned long NumberOfPaths)
{
	double Expiry = TheOption.GetExpiry();

	//double variance = Vol * Vol * Expiry;
	double variance = Vol.IntegralSquare(0,Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	//double movedSpot = Spot * exp(r * Expiry + itoCorrection);
	double movedSpot = Spot*exp(r.Integral(0,Expiry) +	itoCorrection);

	double thisSpot;
	double runningSum = 0;

	for (unsigned long i = 0; i < NumberOfPaths; ++i)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
		runningSum += thisPayOff;
	}

	double mean = runningSum / NumberOfPaths;
	//mean *= exp(-r * Expiry);
	mean *= exp(-r.Integral(0,Expiry));

	return mean;
}
