/*
 * simpleMC.h
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#ifndef SIMPLEMC_H_
#define SIMPLEMC_H_

/*The mechanism for expressing the ‘is a’ relationship in C++ is inheritance.
There are plenty of examples we have already seen where such ‘is a’ relationships
are natural. For example, a call option is a vanilla option. The compiler’s built-in
random number generator is a random number generator. Box–Muller is a method
of turning uniform random variables into Gaussian random variables. An Asian
option is a path-dependent exotic option. An arithmetic Asian call option is an
Asian option, as is a geometric Asian put option. Returning the mean is a way
of gathering statistics for a Monte Carlo simulation. Specifying the continuously
compounding rate is a way to specify the discount curve. The BlackScholes model
is a model of stock price evolution.

The rules of public inheritance say that we can access protected data and methods of the base class
inside the methods of the inherited class but we cannot access the private data. It
is generally recommended to use private data for this reason; if we did otherwise
then any changes in the design of the base class might require that any inherited
classes be rewritten and at the very least all inherited classes would have to be
checked. By using private data, we encapsulate what the base class does, and
allow ourselves to reimplement it in future. It is, however, safe to use protected
methods, as these, similarly to public methods, define part of the object’s in-
terface. As long as the implicit (or ideally explicit) contract which expresses the
method’s functionality does not change, it does not matter what interior changes are
made

When implementing a financial model, we never actually need the instantaneous value of
parameter: it is always the integral or the integral of the square that is important.
*/

#include "PayOff.h"
#include "Vanilla.h"
#include "Parameters.h"
#include "MCStatistics.h"
#include "random2.h"

class testest
{
public:
	void SimpleMonteCarlo(const VanillaOption& TheOption, double Spot,
							const Parameters& Vol, const Parameters& r,
							unsigned long NumberOfPaths,
							StatisticsMC& gatherer, RandomBase& generator);
};

#endif /* SIMPLEMC_H_ */
