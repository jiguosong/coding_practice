/*
 * Handler.h
 *
 *  Created on: Oct 29, 2016
 *      Author: songjiguo
 */

#ifndef HANDLER_H_
#define HANDLER_H_

//Handler.h

#pragma once

#incldue "Application.h"
#include <ext/hash_map>
#include <string>

namespace hf_core  {
	using namespace std;
	using namespace hf_tools;

	class Application; //Application(Application& app) is defined

	class Handler{
	public:
		Application* app() { return m_app; }
		virtual size_t parse(const string&& , size_t len)=0;
		template <typename Str, typename Line_Info> Line_Info getMessage(typename Str);
		virtual ~Handler(){}
	protected:
		Application* m_app;
		hash_map<int N, typename Line_Info > dataMap;
		static string tokenDelimiter; //like ^A (0x01) in fix;
	};
}

#endif /* HANDLER_H_ */
