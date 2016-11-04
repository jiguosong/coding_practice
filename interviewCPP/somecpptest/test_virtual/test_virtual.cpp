/*
 * test_virtual.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: songjiguo
 */

#include "Handler.h"
#include "NYSE_FIX_Handler.h"
#include "ASX_ITCH_Handler.h"

//TO_DO *************
//create a class NYSE_FIX_Handler, which is a protected inheritant of Handler
//http://www.fixtradingcommunity.org/pg/main/what-is-fix
//FIX uses tag 34 value as seqno

class NYSE_FIX_Handler:protected Handler
{

};

//TO_DO *************
//create a class ASX_ITCH_Handler, which is a protected inheritant of Handler
//ASX_ITCH uses Nanoseconds portion of the timestamp as seqno
// http://www.asx.com.au/documents/products/asx_market_data_protocol_specification_v1.0.pdf

class ASX_ITCH_Handler:protected Handler
{

};

//TO_DO **********
//impletement all relevant member functions in Handler.cpp, NYSE_FIX_Handler.cpp and ASX_ITCH_Handler.cpp
