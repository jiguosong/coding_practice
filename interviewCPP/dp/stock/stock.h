/*
 * stock.h
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#ifndef STOCK_H_
#define STOCK_H_

#include <iostream>
#include <vector>

using std::vector;

class stock_buy_sell {
public:
	  int maxProfit(vector<int> &prices);    // one transaction
	  int maxProfit_2(vector<int> &prices);  // many transaction
	  int maxProfit_3(vector<int> &prices);  // at most 2 transaction
	  int maxProfit_4(int k, vector<int> &prices);   // at most k transaction
};

#endif /* STOCK_H_ */
