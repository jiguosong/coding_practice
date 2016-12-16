#include "painthouses.h"

void painthouses::dummy()
{
}

#include <iostream>
unsigned int painthouses::minCost(vector<vector<int>>& costs)
{
	unsigned int cost = 0;

	vector<vector<int>> dp = costs;

	for (int i = 1; i < costs.size(); ++i) {
		dp[i][0] += std::min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += std::min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += std::min(dp[i - 1][0], dp[i - 1][1]);
	}

	return std::min(std::min(dp.back()[0], dp.back()[1]), dp.back()[2]);
}
