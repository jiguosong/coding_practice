/* googletest unit test for C++ */

#include  "preorder_traversal.h"
#include "gtest/gtest.h"
#include <iostream>

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

TEST(testcase_OK1, preorder_traversal)
{
	preorder_traversal c;

	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(7);

	vector<int> ans = c.preOrder(root);

	ASSERT_EQ(ans[0], 1);
	ASSERT_EQ(ans[1], 2);
	ASSERT_EQ(ans[2], 4);
	ASSERT_EQ(ans[3], 5);
	ASSERT_EQ(ans[4], 3);
	ASSERT_EQ(ans[5], 6);
	ASSERT_EQ(ans[6], 7);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
