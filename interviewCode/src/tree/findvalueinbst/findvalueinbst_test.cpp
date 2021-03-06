/*
 * findvalueinbst_test.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "findvalueinbst.h"
#include "gtest/gtest.h"

TEST(findvalueinbst, findval)
{
	findvalInBST c;

	TreeNode *root = randomBST(10, 1, 10);

	int target = 5;

	ASSERT_TRUE(c.findvalueinbst(root, target));

	//int findvalInBST::findvalueinbst(TreeNode *root, int val)
}

TEST(findvalueinbst, cannotfindval)
{
	findvalInBST c;

	TreeNode *root = randomBST(10, 1, 10);

	int target = 12;

	ASSERT_FALSE(c.findvalueinbst(root, target));

	//int findvalInBST::findvalueinbst(TreeNode *root, int val)
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

