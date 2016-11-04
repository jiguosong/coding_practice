/*
 * test_string.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

//use the most ****efficient**** algorithm to
//find the longest common substring between 2 strings

using namespace std;

#include <string>
#include <iostream>
#include <algorithm>

class mysolution {
public:
	string longestCommonSubstring(string* string1, string* string2);
};

string mysolution::longestCommonSubstring(string* string1, string* string2)
{
	string *res = new string;
	if(!string1 || !string2) return *res;

	string s1 = (*string1);
	string s2 = (*string2);

	int m = s1.length();
	int n = s2.length();
	vector<vector<int>> len(m+1, vector<int>(n+1,0));
	len[0][0] = 1;

	int max_len = 0;
	for(int i = 1; i <= m; i++) {
		char c1 = s1.at(i-1);
		for(int j = 1; j <= n; j++) {
			char c2 = s2.at(j-1);
			if(c1 == c2) {
				if(i == 1 || j == 1) len[i][j] = 1;
				else len[i][j] = len[i-1][j-1] + 1;
			}
			if (len[i][j] > max_len) {
				*res = s2.substr(j-len[i][j], len[i][j]);
				max_len = len[i][j];
			}
		}
	}

	return *res;
}

int main(int argc, char **argv) {
	mysolution test;
	string s1 = "OldSite:GeeksforGeeks.org";
	string s2 = "NewSite:GeeksQuiz.com";
	string s3 = "abc";
	string s4 = "abb";
	string ans = test.longestCommonSubstring(&s1, &s2);
	cout << ans << endl;
	ans = test.longestCommonSubstring(&s3, &s4);
	cout << ans;
}

