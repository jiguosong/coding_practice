/*
 * longestnonrepsubstr.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include "longestnonrepsubstr.h"

int longestnonrepsubstr::lengthOfLongestNoRepSubstring(string s)
{
	int res = 0;
	int m[256] = {0};
	int left = 0;

	for (int i = 0; (size_t)i < s.size(); i++) {
		if (m[s[i]-'a'] == 0 || m[s[i]-'a'] < left) {
			res = std::max(res, i-left+1);
		} else {
			left = m[s[i]-'a'];
		}
		m[s[i]-'a'] = i+1;  // make it different from 0
	}
	return res;
}
