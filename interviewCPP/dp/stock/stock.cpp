/*
 * stock.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "stock.h"

// only permitted to complete at most one transaction
// (ie, buy one and sell one share of the stock)
int stock_buy_sell::maxProfit(vector<int> &prices)
{
	int max_profit = 0;
	int min_price = prices[0];

	for(int i = 1; (size_t)i < prices.size(); i++) {
		min_price = std::min(min_price, prices[i]);
		max_profit = std::max(max_profit, prices[i] - min_price);
	}

	return max_profit;
}

// You may complete as many transactions as you like (ie,
// buy one and sell one share of the stock multiple times).
// However, you may not engage in multiple transactions at
// the same time (ie, you must sell the stock before you buy again).
int stock_buy_sell::maxProfit_2(vector<int> &prices)
{
	int max_profit = 0;

	for(int i = 1; (size_t)i < prices.size(); i++) {
		int diff = prices[i] - prices[i-1];
		max_profit += diff > 0 ? diff:0;
	}
	return max_profit;
}


// You may complete at most two transactions
int stock_buy_sell::maxProfit_3(vector<int> &prices)
{
	if(prices.size() == 0) return 0;
	vector<vector<int>> local(prices.size(), vector<int>(3,0));
	vector<vector<int>> global(prices.size(), vector<int>(3,0));

	local[0][0] = 0;
	global[0][0] = 0;

	for(int i = 1; (size_t)i < prices.size(); i++) {
		int diff = prices[i] - prices[i-1];
		for(int j = 1; j < 3; j++) {
			local[i][j] = std::max(global[i-1][j-1] + std::max(diff,0), local[i-1][j]+diff);
			global[i][j] = std::max(local[i][j], global[i-1][j]);
		}
	}

	return global[prices.size()-1][2];

}


// You may complete at most k transactions
int stock_buy_sell::maxProfit_4(int k, vector<int> &prices)
{
	if(prices.size() == 0) return 0;
	vector<vector<int>> local(prices.size(), vector<int>(k+1,0));
	vector<vector<int>> global(prices.size(), vector<int>(k+1,0));

	local[0][0] = 0;
	global[0][0] = 0;

	for(int i = 1; (size_t)i < prices.size(); i++) {
		int diff = prices[i] - prices[i-1];
		for(int j = 1; j < k+1; j++) {
			local[i][j] = std::max(global[i-1][j-1] + std::max(diff,0), local[i-1][j]+diff);
			global[i][j] = std::max(local[i][j], global[i-1][j]);
		}
	}

	return global[prices.size()-1][k];

}



