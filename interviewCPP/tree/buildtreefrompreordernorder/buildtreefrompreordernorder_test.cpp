/* googletest unit test for C++ */

#include "buildtreefrompreordernorder.h"
#include "gtest/gtest.h"
#include <iostream>

#include "../traversal_levelorder/levelorder_traversal.h"
#include "../traversal_inorder/inorder_traversal.h"
#include "../traversal_preorder/preorder_traversal.h"
#include "../traversal_postorder/postorder_traversal.h"
#include "../traversal_verticalorder/verticalorder_traversal.h"

using std::cout; 
using std::endl;

template<class T>
void PrintVector(const vector<T> &vec)
{
	for(size_t i = 0; i < vec.size(); ++i) cout << vec[i] << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for(size_t i = 0; i < vec.size(); ++i) PrintVector(vec[i]);
}

TEST(buildtreefrompreordernorder, normal)
{
	buildtreefrompreordernorder c;
	vector<int> preorder = {7, 10, 4, 3, 1, 2, 8, 11};
	vector<int> inorder = {4, 10, 3, 1, 7, 11, 8, 2};
	TreeNode *root = c.buildTree(preorder, inorder);


	/*
	 *
	 *                     7
	 *                /       	\
	 *              10        	 2
	 *             /  \      	 /
	 *            4    3     	8
	 *                  \      /
	 *                   1 	  11
	 *
	 * */

	ASSERT_EQ(root->val, 7);
	ASSERT_EQ(root->left->val, 10);
	ASSERT_EQ(root->left->left->val, 4);
	ASSERT_EQ(root->left->right->val, 3);
	ASSERT_EQ(root->left->right->right->val, 1);

	ASSERT_EQ(root->right->val, 2);
	ASSERT_EQ(root->right->left->val, 8);
	ASSERT_EQ(root->right->left->left->val, 11);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
