/*
 * validbst.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "validbst.h"
#include <climits>

static bool isValidBST_helper(TreeNode *root, long min, long max);

bool solution::isValidBST(TreeNode *root)
{
	return isValidBST_helper(root, LONG_MIN, LONG_MAX);
}

static bool isValidBST_helper(TreeNode *root, long min, long max)
{
	if(!root) return true;

	if(root->val <= min || root->val >= max) return false;

	return isValidBST_helper(root->left, min, root->val) &&
			isValidBST_helper(root->right, root->val, max);
}
