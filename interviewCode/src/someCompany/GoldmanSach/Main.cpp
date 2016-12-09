/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#include "TradeMonitor.h"
#include "TestData.h"

#include <iostream>

using namespace Gs::Amm;

int main(int argc, char *argv[])
{
    TradeMonitor monitor;
    
    // Part 1: Initial Params and Trades
    loadParamData1();
    loadTradeData1();
    
    // Part 2: Intraday Parameter Change
    loadParamData2();
    loadTradeData2();
    

    std::cout << "test...." << std::endl;

    return 0;
}
