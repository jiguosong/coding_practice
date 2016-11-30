/*
 * maxsubsequncesum_test.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "maxsubsequncesum.h"
#include "gtest/gtest.h"

TEST(testcase_OK1, maxsubsequncesum)
{
	maxsubsequncesum_sol c;

	vector<int> nums = {1,2,3,4};

	ASSERT_EQ(10, c.maxsubsequencesum(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


