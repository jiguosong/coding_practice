/*
 * Task1.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "Task3.h"
#include <iostream>
#include <cmath>
using namespace std;

/*int Task3::solution(int A, int B) {
	cout << "task3..." << endl;
	return -1;
}*/

#include <vector>
#include <stdexcept>
#include <iostream>

/**
*   \brief Adds/appends list of integers at the end of internal list.
*
**/
void Task3::addLast(const std::vector<int>& list)
{
	throw std::logic_error("Waiting to be implemented");
}

/**
*   \brief Returns boolean representing if any three consecutive integers in the internal list have given sum.
*
**/
bool Task3::containsSum3(int sum)
{
	throw std::logic_error("Waiting to be implemented");
}


/*
class NumArray {
public:
    NumArray(vector<int> &nums) {
        num.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    void update(int i, int val) {
        int diff = val - num[i + 1];
        for (int j = i + 1; j < num.size(); j += (j&-j)) {
            bit[j] += diff;
        }
        num[i + 1] = val;
    }
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> num;
    vector<int> bit;
};*/
