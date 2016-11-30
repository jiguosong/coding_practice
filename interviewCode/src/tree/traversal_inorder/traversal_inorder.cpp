/*
 * inorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "traversal_inorder.h"

static void inOrder_helper(TreeNode *root, vector<int> &res)
{
	if(!root) return;
	inOrder_helper(root->left, res);
	res.push_back(root->val);
	inOrder_helper(root->right, res);
}

vector<int> inorder_traversal::inOrder(TreeNode *root)
{
	vector<int> res = {};
	inOrder_helper(root, res);
	return res;
}


