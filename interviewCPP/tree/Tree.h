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

class BTtree {
public:
	TreeNode *root;
	BTtree() {
		root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(4);
		root->right->left = new TreeNode(6);
		root->left->right = new TreeNode(5);
		root->right->right = new TreeNode(7);
	}

	vector<vector<int>> display(TreeNode *root)
	{
		cout << "level order traversal\n";
		vector<vector<int>> res;
		if(!root) return res;

		queue<TreeNode *> q;
		q.push(root);

		int pos = 2;
		while(!q.empty()) {
			int sz = q.size();
			vector<int> tmp;
			for (int i = 0; i < sz; i++) {
				TreeNode *p = q.front();
				q.pop();
				for(int k = 0; k < pos; k++) cout << " ";
				cout << p->val << ' ';
				tmp.push_back(p->val);
				if(p->left) q.push(p->left);
				if(p->right) q.push(p->right);
			}

			res.push_back(tmp);
			pos--;
			std::cout << std::endl;
		}

		return res;
	}

};


class BSTtree {
public:
	TreeNode *root;
	BSTtree() {
		root = new TreeNode(4);
		root->left = new TreeNode(2);
		root->right = new TreeNode(6);
		root->left->left = new TreeNode(1);
		root->right->left = new TreeNode(5);
		root->left->right = new TreeNode(3);
		root->right->right = new TreeNode(7);
	}

	vector<vector<int>> display(TreeNode *root)
	{
		cout << "level order traversal\n";
		vector<vector<int>> res;
		if(!root) return res;

		queue<TreeNode *> q;
		q.push(root);

		int pos = 2;
		while(!q.empty()) {
			int sz = q.size();
			vector<int> tmp;
			for (int i = 0; i < sz; i++) {
				TreeNode *p = q.front();
				q.pop();
				for(int k = 0; k < pos; k++) cout << " ";
				cout << p->val << ' ';
				tmp.push_back(p->val);
				if(p->left) q.push(p->left);
				if(p->right) q.push(p->right);
			}

			res.push_back(tmp);
			pos--;
			std::cout << std::endl;
		}

		return res;
	}
};




#endif /* TREE_TREE_H_ */
