/* googletest unit test for C++ */

#include "traversal_levelorder.h"
#include "gtest/gtest.h"
#include <iostream>

using std::cout;
using std::endl;

template<class T>
void PrintVector(const vector<T> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		cout << vec[i] << ' ';
	cout << endl;
}

template<class T>
void PrintVectorVector(const vector<vector<T>> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		PrintVector(vec[i]);
}

TEST(testcase_OK1, levelorder_traversal)
{
	levelorder_traversal c;

	TreeNode *root = randomBT(7, 1, 100);
	printPretty(root, 2, 4, cout);

	vector<vector<int>> ans = c.levelOrder(root);
	PrintVectorVector(ans);
	cout << endl;
}

TEST(testcase_OK2, levelorder_traversal)
{
	levelorder_traversal c;

	TreeNode *root = nullptr;

	vector<vector<int>> ans = c.levelOrder(root);
	PrintVectorVector(ans);

	ASSERT_TRUE(ans.empty());
	cout << endl;
}

TEST(testcase_OK2, test_randomBSTgenerator)
{
	levelorder_traversal c;

	TreeNode *root = randomBST(10, -1000, 1000);
	printPretty(root, 2, 4, cout);

	vector<vector<int>> ans = c.levelOrder(root);
	PrintVectorVector(ans);

	//ASSERT_TRUE(ans.empty());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
