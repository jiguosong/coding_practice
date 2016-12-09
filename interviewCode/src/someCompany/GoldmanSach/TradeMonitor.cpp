/*
 * TradeMonitor.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: songjiguo
 */

#include "TradeMonitor.h"
#include <thread>

namespace Gs { namespace Amm {

TradeMonitor::TradeMonitor():TimeInterval(2) {
	MonitorQuantity mn_quantity(ParamClient &pc,TradeClient &tc,double TimeInterval);    // acucmulated quantity monitor
	MonitorDelta mn_delta(ParamClient &pc,TradeClient &tc, double TimeInterval);          // delta quantity monitor
}

}
}
