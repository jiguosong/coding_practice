/*
 * validateBST.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: songjiguo
 */

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>
#include "Tree.h"

using std::cout;
using std::string;
using std::vector;
using std::queue;
using namespace std;

BSTtree atree;  // build a tree for testing

class bst_solution {
public:
	virtual void run() = 0;
	virtual ~bst_solution(){};
};

class inordersuccessor : public bst_solution {
public:
	void run() override {
		TreeNode *p = new TreeNode(4);
		TreeNode* ans = inorderSuccessor(atree.root, p);
		cout << "successor ";
		if(ans) cout << ans->val;
	}

	static inordersuccessor &instance()
	{
		static inordersuccessor *p = new inordersuccessor;
		return *p;
	}

	~inordersuccessor(){};
private:
	inordersuccessor(){};
	inordersuccessor(const inordersuccessor &other);
	const inordersuccessor &operator=(const inordersuccessor &other);

	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);
};


TreeNode* inordersuccessor::inorderSuccessor(TreeNode* root, TreeNode* p)
{
	if(!root || !p) return nullptr;

	TreeNode *res;

	// keep tracking the last change to the left
	// only when the p is smaller, and the last one could be potential successor
	while(root) {
		if(root->val > p->val) {
			res = root;
			root = root->left;
		} else root = root->right;
	}

	return res;
}

class ValidBST : public bst_solution {
public:
	void run() override {
		bool res = isValidBST(atree.root);
		if(res) cout << "it is a valid BST";
		else cout << "it is not a valid BST";
	}

	static ValidBST &instance() {
		static ValidBST *p = new ValidBST;
		return *p;
	}

	virtual ~ValidBST(){};
private:
	ValidBST(){};
	ValidBST(const ValidBST &other) = delete;
	const ValidBST &operator=(const ValidBST &other) = delete;
	bool isValidBST(TreeNode *root);
	bool helper(TreeNode *root, int min, int max);
};


bool ValidBST::isValidBST(TreeNode *root)
{
	if(!root) return false;
	return ValidBST::helper(root, INT_MIN, INT_MAX);
}

bool ValidBST::helper(TreeNode *root, int min, int max)
{
	if(!root) return true;
	if(root->val < min || root->val > max) return false;
	return helper(root->left, min, root->val) &&
			helper(root->right, root->val, max);
}


class bst_solution_factory {
public:
	static bst_solution *solve(const string &name)
	{
		if(name == "validate BST") {
			bst_solution &p = ValidBST::instance();
			return &p;
		}

		if(name == "inorder success BST") {
			bst_solution &p = inordersuccessor::instance();
			return &p;
		}

		return nullptr;
	}
};


int main()
{
	atree.display(atree.root);
	cout << endl;
	bst_solution_factory bst_solution;
	bst_solution.solve("validate BST")->run();
	cout << endl;
	bst_solution.solve("inorder success BST")->run();
}
