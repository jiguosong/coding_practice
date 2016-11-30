/*
 * maxsubaaray.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <vector>

using namespace std;

class maxsubarraysum {
public:
	static maxsubarraysum &instance() {
		maxsubarraysum *p = new maxsubarraysum();
		return *p;
	}

	~maxsubarraysum(){};
	int maxSubArray(vector<int>& nums);

private:
	maxsubarraysum(){};
	maxsubarraysum(const maxsubarraysum &other) = delete;
	const maxsubarraysum &operator=(const maxsubarraysum &other) = delete;
};

int maxsubarraysum::maxSubArray(vector<int>& nums)
{
	int sz = nums.size();
	vector<int> maxsum(sz, 0);

	int maxRes = 0;
	maxsum[0] = nums[0];
	for(int i = 1; i < sz; i++) {
		maxsum[i] = max(nums[i], nums[i]+maxsum[i-1]);
		maxRes = max(maxRes, maxsum[i]);
	}

	return maxRes;
}


int main()
{
	maxsubarraysum &test = maxsubarraysum::instance();
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	int ans = test.maxSubArray(nums);
	cout << ans;
}



