/*
 * pathsum.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: songjiguo
 */

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using std::cout;
using std::string;
using std::vector;
using std::queue;

#include "Tree.h"

using namespace std;

BTtree atree;  // a tree for testing

class pathsum {
public:
	  bool hasPathSum(TreeNode *root, int sum);
	  vector<vector<int> > allpathSum(TreeNode *root, int sum);
	  int sumNumbers(TreeNode *root);
};

bool pathsum::hasPathSum(TreeNode *root, int sum)
{
	if(!root) return false;

	if(root->val == sum && !root->left && !root->right) return true;

	return hasPathSum(root->left, sum - root->val) ||
			hasPathSum(root->right, sum - root->val);
}


void helper(TreeNode *root, int sum,  vector<int> &tmp, vector<vector<int>> &res)
{
	if(!root->left && !root->right && root->val == sum) {
		res.push_back(tmp);
		return;
	}

	if(root->left) {
		tmp.push_back(root->left->val);
		helper(root->left, sum-root->val, tmp, res);
		tmp.pop_back();
	}

	if(root->right) {
		tmp.push_back(root->right->val);
		helper(root->right, sum-root->val, tmp, res);
		tmp.pop_back();
	}
}

vector<vector<int>> pathsum::allpathSum(TreeNode *root, int sum)
{
	vector<vector<int>> res;
	if(!root) return res;

	vector<int> tmp;
	tmp.push_back(root->val);
	helper(root, sum, tmp, res);

	return res;
}

int sumNumbers_helper(TreeNode *root, int sum)
{
	if(!root) return 0;
	sum = sum*10 + root->val;
	if(!root->left && !root->right) return sum;
	return sumNumbers_helper(root->left, sum) + sumNumbers_helper(root->right, sum);
}

int pathsum::sumNumbers(TreeNode *root)
{
	return sumNumbers_helper(root, 0);
}

int main()
{
	pathsum test;

	atree.display(atree.root);

	int sum = 8;
	bool res = test.hasPathSum(atree.root, sum);
	if(res == true) cout << "found";
	else cout << "not found";

	vector<vector<int>> ans = test.allpathSum(atree.root, sum);

	cout << endl;
	for(auto e:ans) {
		for(auto i:e) cout << i << ' ';
		cout << endl;
	}

	int sumans = test.sumNumbers(atree.root);
	cout << sumans;

	return 0;

}
