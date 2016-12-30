/* googletest unit test for C++ */

#include  "traversal_preorder.h"
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

	TreeNode *root = randomBT(7, 1, 100);
	printPretty(root, 2, 4, cout);

	vector<int> ans = c.preOrder(root);
	PrintVector(ans);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
