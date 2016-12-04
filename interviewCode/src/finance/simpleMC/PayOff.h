/*
 * PayOff.h
 *
 *  Created on: Dec 3, 2016
 *      Author: songjiguo
 */

#ifndef PAYOFF_H_
#define PAYOFF_H_

class PayOff
{
public:
	PayOff(){};
	virtual double operator()(double Spot) const=0;
	virtual ~PayOff() {};
	virtual PayOff* clone() const=0;  // virtual copy constructor
private:
};

class PayOffCall: public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall() {};
	virtual PayOff* clone() const;
private:
	double Strike;
};

class PayOffPut: public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut() {	};
	virtual PayOff* clone() const;
private:
	double Strike;
};

#endif /* PAYOFF_H_ */
