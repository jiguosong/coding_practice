/* googletest unit test for C++ */

#include  "traversal_sideview.h"
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

TEST(testcase_OK1, sidevieworder_traversal)
{
	sidevieworder_traversal c;

	TreeNode *root = randomBT(7, 1, 100);
	printPretty(root, 1, 4, cout);

	vector<int> ans = c.sideviewOrder(root);
	PrintVector(ans);
}

TEST(testcase_OK2, sidevieworder_traversal)
{
	sidevieworder_traversal c;
	TreeNode *root = nullptr;

	vector<int> ans = c.sideviewOrder(root);

	ASSERT_TRUE(ans.empty());
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
