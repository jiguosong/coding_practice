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

using std::cout;
using std::string;
using std::vector;
using std::queue;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

#endif /* TREE_TREE_H_ */
