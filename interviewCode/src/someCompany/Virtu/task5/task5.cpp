/*




 */

#include "task5.h"

#include <iostream>

using namespace std;

void task5::dummy()
{
}

int task5::numberofRepeatedChar(std::string &str)
{
	int res = 0;
	int count = 1;
	int step = 1;

	for (int i = 1; i < str.size(); ++i) {
		if (str[i] != str[i - 1]) {
			res += count;
			count = 1;
			step = 1;
		} else {
			count += ++step;
		}
	}

	res += count;
	return res;
}
