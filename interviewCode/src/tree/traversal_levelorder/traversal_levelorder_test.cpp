/* googletest unit test for C++ */

#include "traversal_levelorder.h"
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

TEST(testcase_OK1, levelorder_traversal)
{
	levelorder_traversal c;

	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(7);

	vector<vector<int>> ans = c.levelOrder(root);
	PrintVectorVector(ans);

	ASSERT_EQ(ans[0][0], 1);
	ASSERT_EQ(ans[1][0], 2);
	ASSERT_EQ(ans[1][1], 3);
	ASSERT_EQ(ans[2][0], 4);
	ASSERT_EQ(ans[2][1], 5);
	ASSERT_EQ(ans[2][2], 6);
	ASSERT_EQ(ans[2][3], 7);
}

TEST(testcase_OK2, levelorder_traversal)
{
	levelorder_traversal c;

	TreeNode *root = nullptr;

	vector<vector<int>> ans = c.levelOrder(root);
	PrintVectorVector(ans);

	ASSERT_TRUE(ans.empty());
}

TEST(testcase_OK2, test_randomBSTgenerator)
{
	levelorder_traversal c;

	TreeNode *root = randomBST(10, -1000,1000);

	vector<vector<int>> ans = c.levelOrder(root);
	PrintVectorVector(ans);

	//ASSERT_TRUE(ans.empty());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
