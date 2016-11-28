/*
 * parserstrtotree.cpp
 *
 *  Created on: Nov 12, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <string>
#include <stack>
#include "Tree.h""

using namespace std;

// String s="{ name:a, children:[{name:aa, children:[{children:[{name:aaaa}], name:aaa}, {name:aab}]}, {name:ab}]}"

// the tree is {name:roots, children:[lefts, rights]}
TreeNode *parserstr2tree(const string &str)
{
	cout << str << endl;

	string roots, lefts, rights, delimiter;
	TreeNode *root, *left, *right;
	int pos, found;

	// find roots
	delimiter = "name:";
	pos = str.find(delimiter);
	if(pos != -1) {
		roots = str.substr(pos+delimiter.length());
		found = roots.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
		if(found != -1) roots = roots.substr(0, found);
	}

	delimiter = "children:[";
	pos = str.find(delimiter);
	string child_s;
	if(pos != -1) {
		child_s = str.substr(pos+delimiter.length());
		found = child_s.find_last_of("]");
		if(found != -1) child_s = child_s.substr(0, found);
	}


	stack<char> stack;
	int idx = 0;
	for(char c:child_s) {
		if(c == '{' || c == '[') stack.push(c);
		if(c == '}' || c == ']') stack.pop();
		++idx;
		if(stack.empty()) break;
	}

	cout << endl;
	cout << idx;
	lefts = child_s.substr(0, idx);
	rights = child_s.substr(idx+2);
	cout << roots << endl;
	cout << lefts << endl;
	cout << rights << endl;

	parserstr2tree(rights);
	//parserstr2tree(rights);

	//root = new TreeNode(10);  // 10 -> roots
	//root->left = left;
	//root->right = right;

	return root;
}


int main()
{
	string s = "{ name:a, children:[{name:aa, children:[{children:[{name:aaaa}], name:aaa}, {name:aab}]}, {name:ab}]}";
	string ss = "{children:[{lefts}, {rights}], name:roots}";
	TreeNode *ans = parserstr2tree(s);
}
