/* googletest unit test for C++ */

#include  "traversal_postorder.h"
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

TEST(testcase_OK1, postorder_traversal)
{
	postorder_traversal c;

	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(7);

	vector<int> ans = c.postOrder(root);
	PrintVector(ans);
	ASSERT_EQ(ans[0], 4);
	ASSERT_EQ(ans[1], 5);
	ASSERT_EQ(ans[2], 2);
	ASSERT_EQ(ans[3], 6);
	ASSERT_EQ(ans[4], 7);
	ASSERT_EQ(ans[5], 3);
	ASSERT_EQ(ans[6], 1);
}

TEST(testcase_OK2, postorder_traversal)
{
	postorder_traversal c;

	TreeNode *root = nullptr;
	vector<int> ans = c.postOrder(root);
	ASSERT_TRUE(ans.empty());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
