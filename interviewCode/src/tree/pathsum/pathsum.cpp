/*
 * pathsum.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

#include "pathsum.h"

bool pathsum::hasPathSum(TreeNode *root, int sum)
{
	if(!root) return false;

	if(root->val == sum && !root->left && !root->right) return true;

	return hasPathSum(root->left, sum - root->val) ||
			hasPathSum(root->right, sum - root->val);
}


static void helper(TreeNode *root, int sum,  vector<int> &tmp, vector<vector<int>> &res)
{
	if(!root->left && !root->right && root->val == sum) {
		res.push_back(tmp);
		return;
	}

	if(root->left) {
		tmp.push_back(root->left->val);
		helper(root->left, sum-root->val, tmp, res);
		tmp.pop_back();
	}

	if(root->right) {
		tmp.push_back(root->right->val);
		helper(root->right, sum-root->val, tmp, res);
		tmp.pop_back();
	}
}


vector<vector<int> > pathsum::allpathSum(TreeNode *root, int sum)
{
	vector<vector<int>> res;
	if(!root) return res;

	vector<int> tmp;
	tmp.push_back(root->val);
	helper(root, sum, tmp, res);

	return res;
}


