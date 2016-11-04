/*
 * twosum.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class twosum {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> map;
		for (int i = 0; (size_t)i < nums.size(); ++i) {
			int t = target - nums[i];
			if (map.count(t) && map[t] != i){
				return {i, map[t]};
				break;
			}
			map[nums[i]] = i;
		}
		return {};
	}
};

int main(){
	cout << "CPP:twoSum ??" << endl;
	vector<int> input {0, 1 , 2, 3, 4, 5, 6};
	vector<int> res(2);

	twosum testobj;
	res = testobj.twoSum(input, 8);
	cout << res[0] << endl;
	cout << res[1] << endl;

	return 0;
}
