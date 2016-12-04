/*
 * ConvergenceTable.h
 *
 *  Created on: Dec 4, 2016
 *      Author: songjiguo
 */

#ifndef CONVERGENCETABLE_H_
#define CONVERGENCETABLE_H_

#include "MCStatistics.h"
#include "Wrapper.h"

/*
Note that we do not write a copy constructor, destructor or assignment operator
as the class itself does no dynamic memory allocation
*/

class ConvergenceTable: public StatisticsMC
{
public:
	ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);
	virtual StatisticsMC* clone() const;
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double> >
	GetResultsSoFar() const;

private:
	Wrapper<StatisticsMC> Inner;
	std::vector<std::vector<double> > ResultsSoFar;
	unsigned long StoppingPoint;
	unsigned long PathsDone;
};

#endif /* CONVERGENCETABLE_H_ */
