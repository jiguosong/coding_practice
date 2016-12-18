/*
 * Tree.h
 *
 *  Created on: Nov 9, 2016
 *      Author: songjiguo
 */

#ifndef TREE_TREE_H_
#define TREE_TREE_H_

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <random>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;
using std::queue;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr)
	{
	}
	;
};

static TreeNode *generateTree_helper(vector<int> nums, int left, int right)
{
	if (left > right)
		return nullptr;

	int mid = left + (right - left) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = generateTree_helper(nums, left, mid - 1);
	root->right = generateTree_helper(nums, mid + 1, right);

	return root;
}

static void getUniqueArray(const unsigned int size, const int lower_bound,
		const int upper_bound, vector<int> &init_array, bool sorted)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(lower_bound, upper_bound);

	std::set<int> myset;
	while (myset.size() < size) {
		auto e = dist(gen);
		assert(e >= lower_bound && e <= upper_bound);
		const bool is_in = myset.find(e) != myset.end();
		if(is_in == false) {
			myset.insert(e);
			init_array.push_back(e);
		}
	}

	if (sorted == true) std::sort(init_array.begin(), init_array.end());

}

static TreeNode *randomBST(const unsigned int size, const int lower_bound,
		const int upper_bound)
{
	assert(size != 0);
	unsigned int range = upper_bound - lower_bound + 1;
	assert(range > 0 && range >= size);

	vector<int> init_array;
	bool sorted = true;
	getUniqueArray(size, lower_bound, upper_bound, init_array, sorted);
	return generateTree_helper(init_array, 0, init_array.size() - 1);
}

static TreeNode *randomBT(const unsigned int size, const int lower_bound,
		const int upper_bound)
{
	assert(size != 0);
	unsigned int range = upper_bound - lower_bound + 1;
	assert(range > 0 && range >= size);

	vector<int> init_array;
	bool sorted = false;
	getUniqueArray(size, lower_bound, upper_bound, init_array, sorted);
	return generateTree_helper(init_array, 0, init_array.size() - 1);
}

#endif /* TREE_TREE_H_ */

