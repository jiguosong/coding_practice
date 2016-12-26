/*
 Given an integer array with all positive numbers and no duplicates,
 find the number of possible combinations that add up to a positive
 integer target.

 Example:

 nums = [1, 2, 3]
 target = 4

 The possible combination ways are:
 (1, 1, 1, 1)
 (1, 1, 2)
 (1, 2, 1)
 (1, 3)
 (2, 1, 1)
 (2, 2)
 (3, 1)

 Note that different sequences are counted as different combinations.

 Therefore the output is 7.

 Follow up:
 What if negative numbers are allowed in the given array?
 How does it change the problem?
 What limitation we need to add to the question to allow negative numbers?
 */

#include "combination_sum4.h"

void combination_sum4::dummy()
{
}

int combination_sum4::combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target+1, 0);
	dp[0] = 1;

	for(int i = 1; i <= target; ++i) {
		for(auto e:nums) {
			if(i >= e) dp[i] += dp[i-e];
		}
	}

	return dp[target];
}