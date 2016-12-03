/*
 * endian.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>

#define MY_BIG_ENDIAN 0
#define MY_LITTLE_ENDIAN 1

int main() {
	unsigned int i = 1;
	char *p = (char *)&i;

	if (p[0] == 0) cout << "big endian" << endl;
	if (p[0] == 1) cout << "little endian" << endl;
}


