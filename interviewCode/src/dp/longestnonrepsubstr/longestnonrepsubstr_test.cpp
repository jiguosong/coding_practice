/*
 * longestnonrepsubstr_test.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#include "longestnonrepsubstr.h"
#include "gtest/gtest.h"
#include <iostream>

using std::cout;
using std::endl;

TEST(testcase_OK1, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "abcabcbb";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 3);
}

TEST(testcase_OK2, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "bbbbb";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 1);
}


TEST(testcase_OK3, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 0);
}

TEST(testcase_OK4, longestnonrepsubstr)
{
	longestnonrepsubstr c;

	string s = "abcdefg";
	ASSERT_EQ(c.lengthOfLongestNoRepSubstring(s), 7);
}





GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



