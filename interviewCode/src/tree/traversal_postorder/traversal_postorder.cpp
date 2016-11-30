/*
 * inorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "traversal_postorder.h"

static void postOrder_helper(TreeNode *root, vector<int> &res)
{
	if(!root) return;
	postOrder_helper(root->left, res);
	postOrder_helper(root->right, res);
	res.push_back(root->val);
}

vector<int> postorder_traversal::postOrder(TreeNode *root)
{
	vector<int> res = {};
	postOrder_helper(root, res);
	return res;
}


