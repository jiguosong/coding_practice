/*
 * Counter_Test.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: songjiguo
 */

#include "gtest/gtest.h"
#include "Counter.h"

TEST(Counter, Increment) {
      Counter c;
      EXPECT_EQ(0, c.Increment());
      EXPECT_EQ(1, c.Increment());
      EXPECT_EQ(2, c.Increment());
}

GTEST_API_ int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
}

