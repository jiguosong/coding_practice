/*
 * Task1.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "Task2.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

static int calculateHeight_helper(const TreeNode &root, int height) {
	//const TreeNode *p = &root;
	//if (!p) return 0;
	if(&root == nullptr) return 0;

	//if (!p->getLeftChild() && !p->getRightChild()) return height;
	if (!root.getLeftChild() && !root.getRightChild()) return height;
	height = height + 1;

	/*return std::max(calculateHeight_helper(*p->getLeftChild(), height),
			calculateHeight_helper(*p->getRightChild(), height));*/
	return std::max(calculateHeight_helper(*root.getLeftChild(), height),
				calculateHeight_helper(*root.getRightChild(), height));
}

int Task2::calculateHeight(const TreeNode& root) {
	//throw std::logic_error("Waiting to be implemented");

	// iteratively
	//const TreeNode *r = &root;   // no need to check this
	//if (!r) return 0;

	queue<const TreeNode *> q;
	q.push(&root);

	int height = -1;
	while(!q.empty()) {
		int sz = q.size();
		++height;
		for (int i = 0; i < sz; i++) {
			const TreeNode *p = q.front();
			q.pop();
			if (p->getRightChild()) q.push(p->getRightChild());
			if (p->getLeftChild()) q.push(p->getLeftChild());
		}
	}

	//return height;

	// recursively
	int res2 = calculateHeight_helper(root, 0);
	return res2;
}
