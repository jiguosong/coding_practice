/*
 * combination_sum.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "combination_sum.h"

static void combinationSum_helper(vector<int> &candidates, int target, int level, vector<int> &tmp, vector<vector<int>> &res);

vector<vector<int>> solution::combinationSum(vector<int> &candidates, int target)
{
	vector<vector<int>> res;
	vector<int> tmp;

	combinationSum_helper(candidates, target, 0, tmp, res);

	return res;
}


static void combinationSum_helper(vector<int> &candidates, int target,
									 int level, vector<int> &tmp, vector<vector<int>> &res)
{
	if(target < 0) {
		return;
	} else if(target == 0) {
		res.push_back(tmp);
		return;
	} else {
		for(size_t i = level; i < candidates.size(); i++) {
			tmp.push_back(candidates[i]);
			combinationSum_helper(candidates, target-candidates[i], i, tmp, res);
			tmp.pop_back();
		}
	}

}


