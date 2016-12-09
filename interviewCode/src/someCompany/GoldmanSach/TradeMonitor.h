/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#ifndef TRADE_MONITOR_H
#define TRADE_MONITOR_H

#include "ParamClient.h"
#include "TradeData.h"
#include "TradeAlert.h"
#include "TradeClient.h"

#include "MonitorModel.h"
#include <thread>

namespace Gs { namespace Amm {

/**
 * The TradeMonitor class must be implemented by you.  New source files may be added.
 */

struct GroupData;
struct SectorData;
struct SymbolData;

class TradeMonitor 
{
public:
    TradeMonitor();
    TradeMonitor(double interval) : TimeInterval(interval) { // allow to set the interval
    	TradeMonitor();
    }

   	virtual ~TradeMonitor(){}
   	TradeMonitor& operator=(const TradeMonitor& original);
   	TradeMonitor(const TradeMonitor& original);
private:
   	double TimeInterval;
   	std::vector<MonitorModel *> MonitorModels;
};

} // Amm
} // Gs

#endif
