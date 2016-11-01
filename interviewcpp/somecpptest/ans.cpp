/*
 * ans.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: songjiguo
 */

//here we have 3 files
//Handler.h, NYSE_FIX_Handler.h and ASX_ITCH_Handler.h
//................
//(1)
//Handler.h
#pragma once

#incldue "Application.h"
#include <ext/hash_map>
#include <string>

namespace hf_core {
using namespace std;
using namespace hf_tools;

class Application;
//Application(Application& app) is defined

class Handler {
public:
	Application* app() {
		return m_app;
	}
	virtual size_t parse(const string&&, size_t len)=0;
	template<typename Str, typename Line_Info> Line_Info getMessage(
			typename Str);
	virtual ~Handler() {
	}

protected:
	Application* m_app;hash_map<int N, typename Line_Info > dataMap;
	static string tokenDelimiter; //like ^A (0x01) in fix;

};

}

//TO_DO ************
//please finish the following NYSE_FIX_Handler.h
//file 2
//NYSE_FIX_Handler.h

#incldue "Application.h"
#include <ext/hash_map>
#include <string>
#include "Handler.h"



//TO_DO *************
//create a class NYSE_FIX_Handler, which is a protected inheritant of Handler
//http://www.fixtradingcommunity.org/pg/main/what-is-fix
//FIX uses tag 34 value as seqno

class NYSE_FIX_Handler: protected Handler {

};


//TO_DO ************
//please finish the following ASX_ITCH_Handler.h
//file 3
//ASX_ITCH_Handler.h

#incldue "Application.h"
#include <ext/hash_map>
#include <string>
#include "Handler.h"

//TO_DO *************
//create a class ASX_ITCH_Handler, which is a protected inheritant of Handler
//ASX_ITCH uses Nanoseconds portion of the timestamp as seqno
// http://www.asx.com.au/documents/products/asx_market_data_protocol_specification_v1.0.pdf

class ASX_ITCH_Handler:protected Handler
{

};
...
...

//TO_DO **********
//impletement all relevant member functions in Handler.cpp, NYSE_FIX_Handler.cpp and ASX_ITCH_Handler.cpp

