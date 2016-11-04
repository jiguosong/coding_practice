/*
 * palindromepair.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class palindromepairs {
public:
	 vector<vector<int>> palindromePairs(vector<string>& words) {
		 vector<vector<int>> res;
		 unordered_map<string, int> map;

		 for(int i = 0; (size_t)i < words.size(); i++) map[words[i]] = i;

		 for(int i = 0; (size_t)i < words.size(); i++) {
			 string str = words[i];

			 if((map.find("") != map.end()) && isPalindrome(str)) {
				 vector<int> tmp;
				 tmp.push_back(i);
				 tmp.push_back(map[""]);
				 res.push_back(tmp);
				 vector<int> tmp2;
				 tmp2.push_back(map[""]);
				 tmp2.push_back(i);
				 res.push_back(tmp2);
			 }

			 add_one_element(str, i, map, res);

			 for(int k = 1; (size_t)k < str.size(); k++) {
				 string left = str.substr(0,k-1);
				 string right = str.substr(k+1);

				 add_one_element(left, i, map, res);
				 add_one_element(right, i, map, res);
			 }
		 }

		 return res;
	 }


private:
	 void add_one_element(string s, int i, unordered_map<string, int> map, vector<vector<int>> res) {
		 vector<int> *tmp = new vector<int>();
		 reverse(s.begin(), s.end());
		 if((map.find(s) != map.end()) && isPalindrome(s)) {
			 tmp->push_back(i);
			 tmp->push_back(map[s]);
			 res.push_back(*tmp);
		 }
	 }


	 bool isPalindrome(string s) {
		 int left = 0, right = s.size()-1;
		 while(left <= right) {
			 if(s[left] != s[right]) return false;
			 left++;
			 right--;
		 }

		 return true;
	 }
};

int main(int argc, char **argv)
{
	palindromepairs test;

	vector<string> words = {"a", "a"};
	vector<vector<int>> ans = test.palindromePairs(words);

	for(vector<int> e:ans) {
		for(int i : e)
		  cout << i << endl;
	}
}
