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

void testest::SimpleMonteCarlo(const VanillaOption& TheOption,
								  double Spot, const Parameters& Vol,
						          const Parameters& r,
						          unsigned long NumberOfPaths,
						          StatisticsMC& gatherer,
						          RandomBase& generator)
{
	generator.ResetDimensionality(1);

	double Expiry = TheOption.GetExpiry();

	//double variance = Vol * Vol * Expiry;
	double variance = Vol.IntegralSquare(0,Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	//double movedSpot = Spot * exp(r * Expiry + itoCorrection);
	double movedSpot = Spot*exp(r.Integral(0,Expiry) +	itoCorrection);
	double discounting = exp(-r.Integral(0,Expiry));

	double thisSpot;
	//double runningSum = 0;

	JSArray VariateArray(1);

	for (unsigned long i = 0; i < NumberOfPaths; ++i)
	{
		//double thisGaussian = GetOneGaussianByBoxMuller();
		//thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		generator.GetGaussians(VariateArray);
		thisSpot = movedSpot*exp(rootVariance*VariateArray[0]);  // now use random generator
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
		gatherer.DumpOneResult(thisPayOff*discounting);
		//runningSum += thisPayOff;
	}

	return;
	//double mean = runningSum / NumberOfPaths;
	//mean *= exp(-r * Expiry);
	//mean *= exp(-r.Integral(0,Expiry));

	//return mean;
}
