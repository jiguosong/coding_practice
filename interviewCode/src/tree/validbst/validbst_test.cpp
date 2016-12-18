/*
 * validbst_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "validbst.h"

#include "gtest/gtest.h"
#include "../Tree.h"

TEST(validbst_test, validbst1)
{
	solution c;

	TreeNode *root;
	root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(7);

	ASSERT_TRUE(c.isValidBST(root));
}

TEST(validbst_test, validbst2)
{
	solution c;

	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->right->right = new TreeNode(7);

	ASSERT_FALSE(c.isValidBST(root));
}

TEST(validbst_test, testrandBST)
{
	solution c;

	TreeNode *root = randomBST(100, -100,100);
	//TreeNode *root = randomBT(20, 1,100);
	ASSERT_TRUE(c.isValidBST(root));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

