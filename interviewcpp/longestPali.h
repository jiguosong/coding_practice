using namespace std;

#include <string>

class Solution_longestPalindrome{
private:
	void check(const string &s, int idx1, int idx2, string &ret, int &len){
		int j = idx1;
		int k = idx2;
		while(s[j] == s[k] && j >= 0 && k < s.length()) {
			j--;
			k++;
		}
		int tmp_len = k - j + 1 - 2;
		if (tmp_len > len) {
			len = tmp_len;
			ret = s.substr(j+1, len);
		}
	}

public:
	string longestPalindrome(string s) {
		string ret;
		int len;

		if (s.length() == 0 || s.length() == 1) return s;

		len = 1;
		ret = s.substr(0,1);
		if (s[0] == s[1]) {
			len = 2;
			ret = s.substr(0,2);
		}

		for (int i = 1; i < s.length(); i++) {
			check(s, i-1, i+1, ret, len);
			if (s[i] == s[i+1])	{
				check(s, i-1, i+2, ret, len);
			}
		}

		return ret;
	}

	void test(){
		cout << "CPP:longestPalindrome" << endl;
		string result = longestPalindrome("bananas");
		cout << result << endl;
		return;
	}
};
