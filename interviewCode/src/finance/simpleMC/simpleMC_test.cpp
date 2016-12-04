/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "simpleMC.h"
#include "DoubleDigital.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"
#include "ParkMiller.h"

using std::cout;
using std::endl;
using std::vector;

/*
 Choose auto x when you want to work with copies.
 Choose auto &x when you want to work with original items and may modify them.
 Choose auto const &x when you want to work with original items and will not modify them
 */
template<class T>
void PrintVector(const vector<T> &vec)
{
	for (auto const &v : vec)
		cout << v << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for (auto const &v : vec)
		PrintVector(v);
}

TEST(testest, normal)
{
	testest tc;
	double Expiry = 3.5;
	double Strike = 21.3;
	double Spot = 19;
	double Vol = 3001.35;
	double r = 0.8;
	unsigned long NumberOfPaths = 10000;
	double Low = 0.1;
	double Up = 10;

/*	// by reference
	PayOffCall callPayOff(Strike);
	PayOffPut putPayOff(Strike);
	PayOffDoubleDigital doublePayOff(Low,Up);

	// by pointer
	PayOff* thePayOffPtr;
	thePayOffPtr = new PayOffCall(Strike);
	thePayOffPtr = new PayOffPut(Strike);
	thePayOffPtr = new PayOffDoubleDigital(Low,Up);*/

	// after using virtual copy constructor, using an option object
	PayOffCall thePayOff(Strike);
	VanillaOption theOption(thePayOff, Expiry);

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(1);
	AntiThetic GenTwo(generator);

	//double resultCall = tc.SimpleMonteCarlo(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer);
	tc.SimpleMonteCarlo(theOption, Spot, VolParam, rParam, NumberOfPaths,
						gathererTwo, GenTwo);
	vector<vector<double> > results = gatherer.GetResultsSoFar();
	PrintVectorVector<double> (results);

	VanillaOption secondOption(theOption);
	//resultCall = tc.SimpleMonteCarlo(secondOption, Spot, VolParam, rParam, NumberOfPaths, gatherer);
	tc.SimpleMonteCarlo(secondOption, Spot, VolParam, rParam, NumberOfPaths,
						gathererTwo, GenTwo);
	results = gatherer.GetResultsSoFar();
	PrintVectorVector<double> (results);
	//cout << "the price is " << resultCall << "\n";

	PayOffPut otherPayOff(Strike);
	VanillaOption thirdOption(otherPayOff, Expiry);
	theOption = thirdOption;
	//resultCall = tc.SimpleMonteCarlo(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer);
	tc.SimpleMonteCarlo(theOption, Spot, VolParam, rParam, NumberOfPaths,
						gathererTwo, GenTwo);
	results = gatherer.GetResultsSoFar();
	PrintVectorVector<double> (results);
	//cout << "the price is " << resultCall << "\n";
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
