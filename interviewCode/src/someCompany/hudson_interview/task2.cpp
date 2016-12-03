/*
 * task2.cpp
 *
 *  Created on: Nov 12, 2016
 *      Author: songjiguo
 */


#include <iostream>

#include <vector>

#include <set>
using namespace std;

struct tree {
	int x;    // for simplicity. really shoudl use template
	tree *l, *r;
	tree(int val): x(val), l(nullptr), r(nullptr) {}
};

static set<int> distincNum_helper(tree *T);

int solution(tree * T)
{
	int res = 0;
	if(!T) return 0;

	set<int> set = distincNum_helper(T);
	res = set.size();

	return res;

}

static set<int> distincNum_helper(tree *T)
{
	set<int> parent;
	if(!T) return parent;

	set<int> left = distincNum_helper(T->l);  // the set that contains all digits from left tree
	set<int> right = distincNum_helper(T->r); // the set that contains all digits from right tree

	// merge with parent digit
	left.insert(T->x);
	right.insert(T->x);

	// return the larger set
	if(left.size() > right.size()) parent.insert(left.begin(), left.end());
	else parent.insert(right.begin(), right.end());

	return parent;
}


int main()
{
	cout << "Hudson task 2 test...\n";

	tree *root;
	root = new tree(4);

	root->l = new tree(5);
	root->l->l = new tree(4);
	root->l->l->l = new tree(5);

	root->r = new tree(6);
	root->r->l = new tree(1);
	root->r->r = new tree(6);

	tree *nunu;
	int ans = solution(root);
	cout << ans;

}
