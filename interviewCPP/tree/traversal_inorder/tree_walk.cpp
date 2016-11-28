/*
 * tree_walk.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: songjiguo
 */
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "Tree.h"
using std::cout;
using std::string;
using std::vector;
using std::queue;
using namespace std;

BTtree atree;  // build a tree for testing

class tree_walk {
public:
	virtual void run() = 0;
	virtual ~tree_walk(){};
};

// level order walk
class levelorder_walk : public tree_walk {
public:
	void run() override {
		vector<vector<int>> res = levelOrder(atree.root);
	}
	~levelorder_walk(){};

	static levelorder_walk &instance() {
		static levelorder_walk *p = new levelorder_walk();
		return *p;
	}

private:
	levelorder_walk(){};
	levelorder_walk(const levelorder_walk &other) = delete;
	const levelorder_walk &operator=(const levelorder_walk &other) = delete;
	vector<vector<int>> levelOrder(const TreeNode *root);
};

vector<vector<int>> levelorder_walk::levelOrder(const TreeNode *root)
{
	cout << "level order traversal\n";
	vector<vector<int>> res;
	if(!root) return res;

	queue<TreeNode *> q;
	q.push(const root);

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
			if(p->left) q.push(const p->left);
			if(p->right) q.push(const p->right);
		}

		res.push_back(tmp);
		pos--;
		cout << endl;
	}

	return res;
}

// in order walk
class inorder_walk : public tree_walk {
public:
	void run() override {
		cout << "in order traversal\n";
		inOrder(atree.root);
	}
	~inorder_walk(){};

	static inorder_walk &instance() {
		static inorder_walk *p = new inorder_walk();
		return *p;
	}

private:
	inorder_walk(){};
	inorder_walk(const inorder_walk &other) = delete;
	const inorder_walk &operator=(const inorder_walk &other) = delete;
	void inOrder(TreeNode *root);
};

void inorder_walk::inOrder(TreeNode *root)
{
	if(!root) return;

	inOrder(root->left);
	cout << root->val << ' ';
	inOrder(root->right);
}

// pre order walk
class preorder_walk : public tree_walk {
public:
	void run() override {
		cout << "\npre order traversal\n";
		preOrder(atree.root);
	}
	~preorder_walk(){};

	static preorder_walk &instance() {
		static preorder_walk *p = new preorder_walk();
		return *p;
	}

private:
	preorder_walk(){};
	preorder_walk(const preorder_walk &other) = delete;
	const preorder_walk &operator=(const preorder_walk &other) = delete;
	void preOrder(TreeNode *root);
};

void preorder_walk::preOrder(TreeNode *root)
{
	if(!root) return;
	cout << root->val << ' ';
	preOrder(root->left);
	preOrder(root->right);
}

// post order walk
class postorder_walk : public tree_walk {
public:
	void run() override {
		cout << "\npost order traversal\n";
		postOrder(atree.root);
	}
	~postorder_walk(){};

	static postorder_walk &instance() {
		static postorder_walk *p = new postorder_walk();
		return *p;
	}

private:
	postorder_walk(){};
	postorder_walk(const postorder_walk &other) = delete;
	const postorder_walk &operator=(const postorder_walk &other) = delete;
	void postOrder(TreeNode *root);
};

void postorder_walk::postOrder(TreeNode *root)
{
	if(!root) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << ' ';
}


// vertical order walk
class verticalorder_walk : public tree_walk {
public:
	void run() override {
		cout << "\nvertical order traversal\n";
		vector<vector<int>> ans = verticalOrder(atree.root);
		for(auto e : ans) {
			for(auto k : e) cout << k;
			std::cout << std::endl;
		}
	}
	~verticalorder_walk(){};

	static verticalorder_walk &instance() {
		static verticalorder_walk *p = new verticalorder_walk();
		return *p;
	}

private:
	verticalorder_walk(){};
	verticalorder_walk(const verticalorder_walk &other) = delete;
	const verticalorder_walk &operator=(const verticalorder_walk &other) = delete;
	vector<vector<int>> verticalOrder(TreeNode* root);
};

vector<vector<int>> verticalorder_walk::verticalOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if(!root) return res;

	map<int, vector<int>> map;
	queue<pair<int, TreeNode *>> queue;
	queue.push({0, root});
	while(!queue.empty()) {
		auto tmp = queue.front();
		queue.pop();
		map[tmp.first].push_back(const tmp.second->val);
		if(tmp.second->left) queue.push(const {tmp.first-1, tmp.second->left});
		if(tmp.second->right) queue.push(const {tmp.first+1, tmp.second->right});
	}

	for(auto a : map) res.push_back(a.second);
	return res;
}

//rightside_view_walk
class rightside_view_walk : public tree_walk {
public:
	void run() override {
		cout << "\nrightside_view traversal\n";
		vector<int> ans = rightSideView(atree.root);
		for(auto k : ans) cout << k << ' ';
	}
	~rightside_view_walk(){};

	static rightside_view_walk &instance() {
		static rightside_view_walk *p = new rightside_view_walk();
		return *p;
	}

private:
	rightside_view_walk(){};
	rightside_view_walk(const rightside_view_walk &other) = delete;
	const rightside_view_walk &operator=(const rightside_view_walk &other) = delete;
	vector<int> rightSideView(TreeNode *root);
};

vector<int> rightside_view_walk::rightSideView(TreeNode *root)
{
	vector<int> res;
	if(!root) return res;

	queue<TreeNode *> queue;
	queue.push(const root);
	while(!queue.empty()) {
		res.push_back(const queue.back()->val);
		int sz = queue.size();
		for(int i = 0; i < sz; i++) {
			TreeNode *tmp = queue.front();
			queue.pop();
			if(tmp->left) queue.push(const tmp->left);
			if(tmp->right) queue.push(const tmp->right);
		}
	}

	return res;
}


class tree_walk_solution {
public:
	static tree_walk *solve (const string name)
	{
		if(name == "level order") {
			tree_walk &p = levelorder_walk::instance();
			return &p;
		}

		if(name == "in order") {
			tree_walk &p = inorder_walk::instance();
			return &p;
		}

		if(name == "pre order") {
			tree_walk &p = preorder_walk::instance();
			return &p;
		}

		if(name == "post order") {
			tree_walk &p = postorder_walk::instance();
			return &p;
		}

		if(name == "vertical order") {
			tree_walk &p = verticalorder_walk::instance();
			return &p;
		}

		if(name == "right side view") {
			tree_walk &p = rightside_view_walk::instance();
			return &p;
		}

		return nullptr;
	}
};

int main()
{
	tree_walk_solution solution;
	solution.solve("level order")->run();
	solution.solve("vertical order")->run();
	solution.solve("in order")->run();
	solution.solve("pre order")->run();
	solution.solve("post order")->run();
	solution.solve("right side view")->run();
}

