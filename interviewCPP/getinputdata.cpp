/*
 * getinputdata.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "getinputdata.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::ifstream;
using std::istringstream;
using std::stringstream;
using std::cout;
using std::string;

void getinputdata::read_input_int(vector<int> &input_data_int)
{
	ifstream infile("dummy_int_data");
	while (infile) {
		string s;
		if (!getline(infile, s))
			break;

		istringstream ss(s);

		while (ss) {
			string s;
			if (!getline(ss, s, ','))
				break;
			stringstream ints(s);
			int tmp = 0;  // (default value is 0)
			ints >> tmp;
			input_data_int.push_back(tmp);
		}

	}

	if (!infile.eof()) {
		std::cerr << "Failed to read!\n";
	}


}

