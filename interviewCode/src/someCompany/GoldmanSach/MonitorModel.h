/*
 * MonitorType.h
 *
 *  Created on: Dec 7, 2016
 *      Author: songjiguo
 */

#ifndef MONITORMODEL_H_
#define MONITORMODEL_H_

#include <string>
#include <vector>


#include "ParamClient.h"
#include "TradeData.h"
#include "TradeAlert.h"
#include "TradeClient.h"

namespace Gs { namespace Amm {

class MonitorModel
{
public:
	MonitorModel() {};
	virtual ~MonitorModel(){}
	MonitorModel& operator=(const MonitorModel& original);
	MonitorModel(const MonitorModel& original);

	virtual void TriggerAlert() = 0;    // virtual function to trigger the alert
	virtual void RunMonitor() = 0;      // virtual function to run the actual monitor
};

class MonitorQuantity: public MonitorModel
{
public:
	//MonitorQuantity(ParamClient &pc,TradeClient &tc, double Interval_);
	static MonitorQuantity& instance(){
		static MonitorQuantity *instance = new MonitorQuantity;
		return *instance;
	}

	virtual void TriggerAlert();
	virtual void RunMonitor();

private:
	double Interval;
	MonitorQuantity(): Interval(2){};
	~MonitorQuantity(){};
	MonitorQuantity(const MonitorQuantity& other);
	const MonitorQuantity &operator=(const MonitorQuantity& other);
};

class MonitorDelta: public MonitorModel
{
public:
	//MonitorDelta(ParamClient &pc,TradeClient &tc, double Interval_);
	static MonitorDelta& instance(){
		static MonitorDelta *instance = new MonitorDelta;
		return *instance;
	}

	virtual void TriggerAlert();
	virtual void RunMonitor();

private:           // singleton, onyl one monitor
	double Interval;
	MonitorDelta(): Interval(2){};
	~MonitorDelta(){};
	MonitorDelta(const MonitorDelta& other);
	const MonitorDelta &operator=(const MonitorDelta& other);



};


/*static solution& instance(){static solution *instance = new solution; return *instance;}

private:
	solution(){};
	~solution(){};
	solution(const solution& other);
	const solution &operator=(const solution& other);*/

}
}

#endif
