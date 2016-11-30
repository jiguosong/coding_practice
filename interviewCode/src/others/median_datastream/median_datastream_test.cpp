/*
 * median_datastream_test.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "median_datastream.h"

#include "gtest/gtest.h"

TEST(testcase_OK1, median_datastream)
{
	median_datastream c;
	c.addNum(1);
	c.addNum(2);
	ASSERT_EQ(1.5, c.findMedian());
	c.addNum(3);
	ASSERT_EQ(2, c.findMedian());
}

TEST(testcase_OK2, median_datastream)
{
	median_datastream c;
	c.addNum(2);
	c.addNum(3);
	c.addNum(4);
	ASSERT_EQ(3, c.findMedian());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



