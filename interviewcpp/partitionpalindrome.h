/*
 * partitionpalindrome.h
 *
 *  Created on: Sep 5, 2016
 *      Author: songjiguo
 */

#ifndef PARTITIONPALINDROME_H_
#define PARTITIONPALINDROME_H_

using namespace std;

class Solution_partitionpalindrome{

private:
	void print_vs(vector<string> vs) {
		for (int i = 0; i < vs.size(); i++) {
			cout << vs[i] + ",";
		}
	}

	void print_vvs(vector<vector<string>> vvs) {
		for (int i = 0; i < vvs.size(); i++) {
			cout << "[ ";
			print_vs(vvs[i]);
			cout << " ]";
		}
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

private:
	void partition_palindrome_helper(string s, int level, vector<string> &tmp, vector<vector<string>> &res){

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
	}

public:
	vector<vector<string>> partition_palindrome(string s){
		vector<vector<string>> res;
		vector<string> tmp;

		int sz = s.length();
		if (sz == 0) return res;

		partition_palindrome_helper(s, 0, tmp, res);

		print_vvs(res);
		return res;
	}

	void test(){
		vector<vector<string>> res = partition_palindrome("aab");

	}
};



#endif /* PARTITIONPALINDROME_H_ */
