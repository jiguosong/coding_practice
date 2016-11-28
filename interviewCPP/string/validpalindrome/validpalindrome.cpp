/*
 * validpalindrome.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#include "validpalindrome.h"

static bool isNum(char c)
{
	return (c >= '0' && c <= '9');
}

bool isAlpha(char &c) {
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') {
		c = c - 'A' + 'a';   // ignoring cases
		return true;
	}
	return false;
}

/*Given a string, determine if it is a palindrome, considering only alphanumeric
 * characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. */

bool validpalindrome::isValidPalindromeStr(string s)
{
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

/*Determine whether an integer is a palindrome. Do this without extra space.*/
bool validpalindrome::isPalindromenumber(int num)
{
	int k = 0;
	int p = num;

	while(p) {
		k = k*10 + p%10;
		p = p/10;
	}
	return (k == num);
}

