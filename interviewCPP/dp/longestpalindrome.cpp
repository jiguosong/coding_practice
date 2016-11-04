using namespace std;

#include <iostream>
#include <string>
#include <vector>

class longestPalindrome {
public:
	string longestpalindrome(string s) {
		if(s.length() == 0 || s.length() == 1) return s;

		string res;
		int max_len = 0;
		int start = 0;
		int end = 0;
		int n = s.length();

		// issues: 1) no warning when exceed the boundary 2) slow
		// vector<vector<bool>> longest(n, vector<bool>(n,false));

		bool longest[n][n];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				longest[i][j] = false;
			}
		}


/*		// or using new
		bool** ary = new bool*[n+1];
		for(int i = 0; i < n+1; ++i) {
		    ary[i] = new bool[n+1];
		    for(int j = 0; j < n+1; ++j) {
		    	ary[i][j] = false;
		    }
		}*/

		longest[0][0] = true;
		for(int j = 1; j <= n; j++) {
			longest[j][j] = true;
			for(int i = 0; i < j; i++) {
				if(s[i] == s[j] && (longest[i+1][j-1] == true || j-i < 2)) {
					longest[i][j] = true;
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

	/*string longestpalindrome(string s)
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
*/
};

int main(int argc, char **argv)
{
	longestPalindrome test;
	string s = "bananas";
	cout << s << endl;
	string ans = test.longestpalindrome(s);
	cout << ans << endl;
}
