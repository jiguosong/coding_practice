/*
 * task1.cpp
 *
 *  Created on: Nov 12, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <string>

#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>


#include <vector>
#include <limits>

using namespace std;

static void permute_helper(vector<int> &nums, int level,
							 vector<bool> &visited, vector<int> &tmp, int &res);

// my solution
int solution(int N) {
	cout << N << endl;

	//int res = numeric_limits<int>::min();
	int res = 0;
	vector<int> nums, tmp;

	// extract digits and put into a vector
	while(N) {
		nums.push_back(N%10);
		N /= 10;
	}

	vector<bool> visited(nums.size(), false);
	permute_helper(nums, 0, visited, tmp, res);

	cout << "max " << res << endl;
	return res;

}

static void permute_helper(vector<int> &nums, int level, vector<bool> &visited, vector<int> &tmp, int &res){
	if (tmp.size() == nums.size()) {
		//for(int i:tmp) cout << i << ' ';
		int k = 0;
		// convert vect to number
		for(int i:tmp) {
			k = k*10 + i;
			if(abs(k) > numeric_limits<int>::max()/10) return;    // for overflow case, simply treat as 0 for now
		}

		res = max(res, k);              // update the max result
		return;
	}

	for (int i = 0; (size_t)i < nums.size(); i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		tmp.push_back(nums[i]);
		permute_helper(nums, i+1, visited, tmp, res);
		visited[i] = false;
		tmp.pop_back();
	}
}

int main()
{
	cout << "Hudson Task 1 testing..." << endl;

	solution(10000);
}



