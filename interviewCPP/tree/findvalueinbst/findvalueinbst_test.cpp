/*
 * findvalueinbst_test.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "findvalueinbst.h"
#include "gtest/gtest.h"

TEST(testcase_OK1, findvalueinbst)
{
	findvalInBST c;

	TreeNode *root;
	root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(7);

	int target = 5;

	ASSERT_TRUE(c.findvalueinbst(root, target));

	//int findvalInBST::findvalueinbst(TreeNode *root, int val)
}

TEST(testcase_OK2, findvalueinbst)
{
	findvalInBST c;

	TreeNode *root;
	root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(7);

	int target = 9;

	ASSERT_FALSE(c.findvalueinbst(root, target));

	//int findvalInBST::findvalueinbst(TreeNode *root, int val)
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

