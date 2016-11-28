/*
 * countersmallernumberafterself_test.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */


#include "countersmallernumberafterself.h"
#include "gtest/gtest.h"
#include <iostream>

using std::cout;
using std::endl;

TEST(testcase_OK1, countersmallernumberafterself)
{
	countersmallernumberafterself c;

	vector<int> nums = {5, 2, 6, 1, -5};
	vector<int> ans = c.countSmaller(nums);
	vector<int> expect = {3,2,2,1,0};
	for(int i = 0; (size_t)i < ans.size(); ++i) ASSERT_EQ(ans[i], expect[i]);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
