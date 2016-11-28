/*
 * preorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "preorder_traversal.h"

static void preOrder_helper(TreeNode *root, vector<int> &res)
{
	if(!root) return;
	res.push_back(root->val);
	preOrder_helper(root->left, res);
	preOrder_helper(root->right, res);
}

vector<int> preorder_traversal::preOrder(TreeNode *root)
{
	vector<int> res = {};
	preOrder_helper(root, res);
	return res;
}


