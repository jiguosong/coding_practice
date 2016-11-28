/*
 * partitionpalindrome.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class partitionPalindrome {
public:
	vector<vector<string>> partition_palindrome(string s){
		vector<vector<string>> res;
		vector<string> tmp;

		int sz = s.length();
		if (sz == 0) return res;

		partition_palindrome_helper(s, 0, tmp, res);

		return res;
	}

private:
	void partition_palindrome_helper(string s, int level, vector<string> &tmp, vector<vector<string>> &res) {
		if (level == s.length()) {
			res.push_back(tmp);
			return;
		}

		for (int i = level; i < s.length(); i++) {
			string tmp_str = s.substr(level,i-level+1);
			if (isvalidPalindrome(tmp_str)) {
				tmp.push_back(tmp_str);
				partition_palindrome_helper(s, i+1, tmp, res);
				tmp.pop_back();
			}
		}

		return;

		return;
	}
private:
	bool isvalidPalindrome(string s){
		int l = 0;
			int r = s.length()-1;

			while(l < r) {
				if (s[l] != s[r]) return false;
				l++;
				r--;
			}

			return true;
	}
};

int main(int argc, char** argv) {
	partitionPalindrome test;
	vector<vector<string>> res = test.partition_palindrome("aab");

	vector<vector<string>>::iterator myiterator;
	for(myiterator = res.begin(); myiterator != res.end(); myiterator++) {
		vector<string>::iterator it;
		for(it = (*myiterator).begin(); it != (*myiterator).end(); it++) {
			cout << *it << " ";
		}
	}

}


