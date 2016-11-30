/*
 * distinctsubsequence_test.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */


#include "distinctsubsequence.h"
#include "gtest/gtest.h"
#include <iostream>

using std::cout;
using std::endl;

TEST(testcase_OK1, distinctsubsequence)
{
	distinctsubsequence c;
	string s = "rabbbit";
	string t = "rabbit";
	ASSERT_EQ(3, c.numDistinct(s, t));
}

TEST(testcase_OK2, distinctsubsequence)
{
	distinctsubsequence c;
	string s = "rabbbit";
	string t = "";
	ASSERT_EQ(1, c.numDistinct(s, t));
}

TEST(testcase_OK3, distinctsubsequence)
{
	distinctsubsequence c;
	string s = "";
	string t = "abc";
	ASSERT_EQ(0, c.numDistinct(s, t));
}

TEST(testcase_OK4, distinctsubsequence)
{
	distinctsubsequence c;
	string s = "abc";
	string t = "abc";
	ASSERT_EQ(1, c.numDistinct(s, t));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

