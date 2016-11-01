/*
 * mostwater.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <vector>
#include <assert.h>
#include <limits.h>

class trappingmostwater {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size()-1;

		int maxwater = 0;

		while(left < right) {
			int w = right - left;
			int h = min(height[left], height[right]);
			maxwater = max(maxwater, w*h);
			if(height[left] < height[right]) ++left;
			else --right;
		}
		return maxwater;
	}
};

int main(int argc, char **argv) {
	trappingmostwater test;
	vector<int> height = {1,2,3,4,5};
	int ans = test.maxArea(height);
	cout << ans << endl;

	return 0;
}
