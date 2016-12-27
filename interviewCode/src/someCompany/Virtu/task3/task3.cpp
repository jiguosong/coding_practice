/*




 */

#include "task3.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

void task3::dummy()
{
}

std::string task3::solution(std::string &S)
{
	stringstream ints(S);
	unsigned long long tmp = 0;
	ints >> tmp;

	std::stringstream stream;
	stream << std::hex << tmp;
	std::string hex(stream.str());

	cout << tmp << "\n";
	cout << hex << "\n";

	string res = "";
	for (auto c : hex) {
		if (c == '1')
			res.push_back('I');
		else if (c == '0')
			res.push_back('O');
		else if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F')
			res.push_back(c);
		else if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f')
			res.push_back(toupper(c));
		else
			return "ERROR";
	}

	return res;
}
