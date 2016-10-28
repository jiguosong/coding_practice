using namespace std;

#include <iostream>
#include <string>

class longestPalindrome {
public:
	string longestpalindrome(string s)
	{
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
			isPalindrome(s, i-1, i+1, ret, len);
			if (s[i] == s[i+1])	{
				isPalindrome(s, i-1, i+2, ret, len);
			}
		}

		return ret;
	}


private:
	void isPalindrome(const string &s, int idx1, int idx2, string &ret, int &len){
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

};

int main(int argc, char **argv)
{
	longestPalindrome test;
	string s = "bananas";
	string ans = test.longestpalindrome(s);
	cout << ans << endl;
}
