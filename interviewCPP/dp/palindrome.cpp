/*
 * palindromeNum.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: songjiguo
 */

using  namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class palindrome {
public:
	virtual void run() = 0;
	virtual ~palindrome(){};
};

////////////////////
// number palindrome
////////////////////
class Num_palindrome : public palindrome {
public:
	void run() override {   // overloading
		int x = 323;
		bool res = false;

		res = isPalindrome(x);
		if(res) cout << "Yes, palindrome number " << x << endl;
		else cout << "No, not palindrome number " << x << endl;
	}

	static Num_palindrome &instance() {
		static Num_palindrome *p = new Num_palindrome;
		return *p;
	}

	virtual ~Num_palindrome(){};
private:
	Num_palindrome(){};
	Num_palindrome(const Num_palindrome &other);
	const Num_palindrome &operator=(const Num_palindrome &other);

	bool isPalindrome(int x);
};

// without using extra space
bool Num_palindrome::isPalindrome(int x) {
	if(x < 0) return false;

	int div = 1;
	while(x/div > 10) div *= 10;
	while(x) {
		if(x/div != x%10) return false;
		x = (x%div)/10;   // remove left and right
		div /= 100;       // remove 2 digits
	}
	return true;
}


////////////////////
// longest palindrome
////////////////////
class longest_palindrome : public palindrome {
public:
	void run() override {
		string s = "bananas";
		string res;

		res = longestpalindrome(s);
		cout << res << endl;
	}

	static longest_palindrome &instance() {
		static longest_palindrome *p = new longest_palindrome;
		return *p;
	}
private:
	longest_palindrome(){};
	~longest_palindrome(){};
	string longestpalindrome(string s);
};

string longest_palindrome::longestpalindrome(string s) {
	if(s.length() == 0 || s.length() == 1) return s;

	string res;
	int max_len = 0;
	int start = 0;
	int end = 0;
	int n = s.length();

	// issues: 1) no warning when exceed the boundary 2) slow
	// vector<vector<bool>> longest(n, vector<bool>(n,false));

	bool palind[n][n];  // if substr(i, i+j) is palindrome
	for(int i = 0; i < n*n; i++) {palind[i/n][i%n] = false;}

	palind[0][0] = true;
	for(int j = 1; j <= n; j++) {
		palind[j][j] = true;
		for(int i = 0; i < j; i++) {
			if(s[i] == s[j] && (palind[i+1][j-1] == true || j-i < 2)) {
				palind[i][j] = true;
				if(j-i+1 > max_len) {
					max_len = j-i+1;
					start = i;
					end = j;
				}
			}
		}
	}

	return s.substr(start, max_len);
}

////////////////////
// palindrome pair
////////////////////

class palindrome_pair : public palindrome {
public:
	void run() override {
		vector<vector<int>> res;
		vector<string> words = {"bat", "tab", "cat"};

		res = palindromePairs(words);
		for(vector<int> e:res) {
			for(int i : e)
			  cout << i << ' ';
			cout << endl;
		}
	}

	static palindrome_pair &instance() {
		static palindrome_pair *p = new palindrome_pair;
		return *p;
	}

	~palindrome_pair(){};
private:
	vector<vector<int>> palindromePairs(vector<string>& words);
	bool isPalindrome(const string str);
	void add_one_element(string s, int i, unordered_map<string, int> map, vector<vector<int>> &res);

	palindrome_pair(){};
	palindrome_pair(const palindrome_pair &other);
	const palindrome_pair &operator=(const palindrome_pair &other);
};

vector<vector<int>> palindrome_pair::palindromePairs(vector<string>& words) {
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

	 palindrome_pair::add_one_element(str, i, map, res);

	 for(int k = 1; (size_t)k < str.size(); k++) {
		 string left = str.substr(0,k-1);
		 string right = str.substr(k+1);

		 palindrome_pair::add_one_element(left, i, map, res);
		 palindrome_pair::add_one_element(right, i, map, res);
	 }
	}

	return res;
}

void palindrome_pair::add_one_element(string s, int i, unordered_map<string, int> map, vector<vector<int>> &res) {
	 vector<int> *tmp = new vector<int>();
	 reverse(s.begin(), s.end());
	 if((map.find(s) != map.end()) && palindrome_pair::isPalindrome(s)) {
		 tmp->push_back(i);
		 tmp->push_back(map[s]);
		 res.push_back(*tmp);
	 }
}

bool palindrome_pair::isPalindrome(const string s) {
	int left = 0, right = s.size()-1;
		 while(left <= right) {
			 if(s[left] != s[right]) return false;
			 left++;
			 right--;
		 }

		 return true;
}

////////////////////
// solution factory
////////////////////

class solution {
public:
	static palindrome *palindrome_solution(const string &name) {
		if(name == "numerPalindrome") {
			palindrome &p = Num_palindrome::instance();
			return &p;
		}

		if(name == "longestPalindrome") {
			palindrome &p = longest_palindrome::instance();
			return &p;
		}

		if(name == "palindrome pairs") {
			palindrome &p = palindrome_pair::instance();
			return &p;
		}

		return NULL;
	}
};

int main() {
	solution solution_factory;
	solution_factory.palindrome_solution("numerPalindrome")->run();

	solution_factory.palindrome_solution("longestPalindrome")->run();

	solution_factory.palindrome_solution("palindrome pairs")->run();
}
