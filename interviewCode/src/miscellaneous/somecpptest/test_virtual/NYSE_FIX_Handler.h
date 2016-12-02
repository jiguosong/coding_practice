/*
 * NYSE_FIX_Handler.h
 *
 *  Created on: Oct 29, 2016
 *      Author: songjiguo
 */


//TO_DO ************
//please finish the following NYSE_FIX_Handler.h
//file 2: NYSE_FIX_Handler.h
//create a class NYSE_FIX_Handler, which is a protected inheritant of Handler
//http://www.fixtradingcommunity.org/pg/main/what-is-fix
//FIX uses tag 34 value as seqno

#ifndef NYSE_FIX_HANDLER_H_
#define NYSE_FIX_HANDLER_H_

#include "Application.h"
#include <ext/hash_map>
#include <string>
#include "Handler.h"

#include <exception>

class Handler;  // add this to make the inheritance work

class NYSE_FIX_Handler:protected Handler
{
public:
	size_t parse(const std::string &&str, size_t len);
};


// Unable to parse message -- define a dummy exception for the meesage parsing error
class MessageParseError : public std::exception
{
  MessageParseError( const std::string& what = "" )
    : error_msg_( "Could not parse message", what ) {}

protected:
    std::string error_msg_;
};

typedef int Line_Infor;  // dummy type for test

template<typename Str, typename Line_Info>
Line_Infor getMessage(Str s1, Line_Info s2)
{

}

size_t NYSE_FIX_Handler::parse(const std::string &&str, size_t len)
throw (MessageParseError)
{
	std::string::size_type position = str.find("\001" "34=");
	if (position == std::string::npos) throw (MessageParseError);

	std::string::size_type startValue = position + 4;
	std::string::size_type soh = str.find_first_of( '\001', startValue );
	if (soh == std::string::npos) throw (MessageParseError);

	std::string value = str.substr(startValue, soh - startValue);

	return value;
}


#endif /* NYSE_FIX_HANDLER_H_ */
