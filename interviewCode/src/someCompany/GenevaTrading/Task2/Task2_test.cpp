/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "Task2.h"

using std::cout; 
using std::endl;
using std::vector;

/*
   Choose auto x when you want to work with copies.
   Choose auto &x when you want to work with original items and may modify them.
   Choose auto const &x when you want to work with original items and will not modify them 
*/
template<class T>
void PrintVector(const vector<T> &vec)
{
	for(auto const &v:vec) cout << v << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for(auto const &v:vec) PrintVector(v);
}

TEST(Task2, normal)
{
	Task2 tc;

	TreeNode* leaf0 = new TreeNode(NULL, NULL);
	TreeNode* leaf1 = new TreeNode(NULL, leaf0);
	TreeNode* leaf2 = new TreeNode(NULL, NULL);
	TreeNode* node = new TreeNode(leaf1, NULL);
	TreeNode* root = new TreeNode(node, leaf2);

	ASSERT_EQ(3, tc.calculateHeight(*root));
}

TEST(Task2, normal2)
{
	Task2 tc;

	TreeNode* leaf2 = new TreeNode(NULL, NULL);
	TreeNode* node = new TreeNode(NULL, NULL);
	TreeNode* root = new TreeNode(node, leaf2);

	ASSERT_EQ(1, tc.calculateHeight(*root));
}

TEST(Task2, normal3)
{
	Task2 tc;

	TreeNode* root = new TreeNode(NULL, NULL);

	ASSERT_EQ(0, tc.calculateHeight(*root));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
