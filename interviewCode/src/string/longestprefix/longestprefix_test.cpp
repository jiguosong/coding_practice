/*
 * longestprefix_test.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: songjiguo
 */

#include "longestprefix.h"

#include "gtest/gtest.h"

#include <iostream>
using std::cout;
using std::endl;

TEST(testcase_OK1, longestprefix)
{
	longestprefix c;
	vector<string> strs = {"abc", "def"};
	ASSERT_EQ("", c.longestCommonPrefix(strs));
}

TEST(testcase_OK2, longestprefix)
{
	longestprefix c;
	vector<string> strs = {"abc", "abd"};
	string ans = c.longestCommonPrefix(strs);
	cout << ans << endl;
	ASSERT_EQ("ab", ans);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
