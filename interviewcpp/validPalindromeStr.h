/*
 * validPalindromeStr.h
 *
 *  Created on: Sep 5, 2016
 *      Author: songjiguo
 */

#ifndef VALIDPALINDROMESTR_H_
#define VALIDPALINDROMESTR_H_

using namespace std;

class Solution_validPalindromeStr{
private:
	bool isNum(char c) {
		if (c >= '0' && c <= '9') return true;
		return false;
	}

private:
	bool isAlpha(char &c) {
		if (c >= 'a' && c <= 'z') return true;
		if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
			return true;
		}
		return false;
	}

public:
	bool isValidPalindromeStr(string s){
		if (s.length() == 0) return true;

		int l = 0;
		int r = s.length()-1;

		while(l < r) {

			while (!isNum(s[l]) && !isAlpha(s[l])) l++;
			while (!isNum(s[r]) && !isAlpha(s[r])) r--;
			if (s[l] != s[r]) return false;
			l++;
			r--;
		}

		return true;
	}

	void test(){
		if (isValidPalindromeStr("Red rum, sir, is murder")) cout << "yes" << endl;
		else cout << "no" << endl;
	}
};


#endif /* VALIDPALINDROMESTR_H_ */
