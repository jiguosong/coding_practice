/*
 * palindromenumber.h
 *
 *  Created on: Sep 5, 2016
 *      Author: songjiguo
 */

#ifndef PALINDROMENUMBER_H_
#define PALINDROMENUMBER_H_

using namespace std;

class Solution_palindromenumber{
public:
	bool isPalindromenumber(int num) {
		int k = 0;
		int p = num;

		while(p) {
			k = k*10 + p%10;
			p = p/10;
		}

		return (k == num);
	}

	void test(){
		cout << "CPP:isPalindromenumber" << endl;
		int num = 121;
		if (isPalindromenumber(num)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
};


#endif /* PALINDROMENUMBER_H_ */
