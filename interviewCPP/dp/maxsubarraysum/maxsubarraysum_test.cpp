/*
 * maxsubarraysum_test.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "maxsubarraysum.h"

TEST(testcase_OK, maxsubarraysum)
{
	solution c;
	std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	int res = c.maxSubArray(nums);
	EXPECT_EQ(res, 6);
}

TEST(testcase_OK2, maxsubarraysum)
{
	solution c;
	std::vector<int> nums = {-1,-1,-1,1,-1,-1,-1,-1};
	int res = c.maxSubArray(nums);
	EXPECT_EQ(res, 1);
}

TEST(testcase_Allnegative, maxsubarraysum)
{
	solution c;
	std::vector<int> nums = {-10, -2, -5, -12};
	int res = c.maxSubArray(nums);
	EXPECT_EQ(res, -2);
}

TEST(testcase_OK3, maxsubarraysum)
{
	solution c;
	std::vector<int> nums = {1,1,1,1,1,1,-100,1};
	int res = c.maxSubArray(nums);
	EXPECT_EQ(res, 6);
}

TEST(testcase_OK4, maxsubarraysum)
{
	solution c;
	std::vector<int> nums = {0};
	int res = c.maxSubArray(nums);
	EXPECT_EQ(res, 0);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

