/*
 * GotW02.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: songjiguo
 */

#include <string>
#include <list>

using namespace std;

typedef string employee;

string find_addr(const list<employee> &emps, const string &name) {
	const auto i = find(begin(emps), end(emps), name);
	//return i != end(emps) ? i->addr : "";
    return "";
}

int main()
{}

