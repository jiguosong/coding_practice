/*
 * maxsubarraysum.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "maxsubarraysum.h"


int solution::maxSubArray(std::vector<int>& nums)
{
	int res = 0;

	std::vector<int> maxsum(nums.size(), 0);
	maxsum[0] = nums[0];
	res = maxsum[0];

	for(unsigned int i  = 1; i < nums.size(); ++i) {
		maxsum[i] = std::max(maxsum[i-1]+nums[i], nums[i]);
		res = std::max(res, maxsum[i]);
	}
	return res;
}

/*   -- this will not handle the case of all negative
 *
 *  in another word, this method is looking for the min positive subsequence

Simple idea of the Kadane's algorithm is to look for all positive contiguous segments of the array
(max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive
segments (max_so_far is used for this). Each time we get a positive sum compare it with max_so_far and
update max_so_far if it is greater than max_so_far
int solution::maxSubArray(std::vector<int>& nums)
{
	int max_so_far = 0;
	int max_ending_here = 0;
	for(unsigned int i  = 0; i < nums.size(); ++i) {
		max_ending_here = std::max(0, max_ending_here+nums[i]);
		max_so_far = std::max(max_so_far, max_ending_here);
	}
	return max_so_far;
}

*/
