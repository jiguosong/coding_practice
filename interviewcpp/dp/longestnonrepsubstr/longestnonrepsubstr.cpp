using namespace std;

#include <iostream>

class longestnonrepsubstr{
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		int m[256] = {0};
		int left = 0;

		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]] == 0 || m[s[i]] < left) {
				res = max(res, i-left+1);
			} else {
				left = m[s[i]];
			}
			m[s[i]] = i+1;  // make it different from 0
		}
		return res;
	}


};

int main(){
	cout << "CPP:lengthOfLongestSubstring" << endl;
	string A = "abbca";
	cout << A << endl;

	longestnonrepsubstr test;
	int result = test.lengthOfLongestSubstring(A);
	cout << result << endl;

	return 0;
}
