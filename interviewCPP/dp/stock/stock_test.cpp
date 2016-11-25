/*
 * stock_test.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "stock.h"

#include "gtest/gtest.h"
#include "../../INPUT_DATA/getinputdata.h"

TEST(testcase_OK1, stock1)
{
	stock_buy_sell c;

	vector<int> prices = {7, 1, 5, 3, 6, 4};
	ASSERT_EQ(5, c.maxProfit(prices));

}

TEST(testcase_OK2, stock2)
{
	stock_buy_sell c;

	vector<int> prices = {2, 1, 3, 4, 5, 4, 2, 8, 7};
	ASSERT_EQ(10, c.maxProfit_2(prices));

}

TEST(testcase_OK3, stock3)
{
	stock_buy_sell c;

	vector<int> prices = {4,4,6,1,1,4,2,5};
	ASSERT_EQ(6, c.maxProfit_3(prices));
}

TEST(testcase_OK4, stock4)
{
	stock_buy_sell c;

	vector<int> prices;

	getinputdata gpd;
	gpd.read_input_int(prices);

	ASSERT_EQ(2000, c.maxProfit_4(2, prices));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
