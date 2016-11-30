/*
 * longestprefix.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: songjiguo
 */

#include "longestprefix.h"

string longestprefix::longestCommonPrefix(vector<string>& strs)
{
	if(strs.size() == 0) return "";

	for(int i = 0; (size_t)i < strs[0].size(); i++) {
		for(int j = 0; (size_t)j < strs.size()-1; j++) {
			if((size_t)i >= strs[j].size() || strs[j][i] != strs[j+1][i]) {
				return strs[j].substr(0, i);
			}
		}
	}

	return strs[0];
}
