/* googletest unit test for C++ */


#include "inordersuccessorbst.h"
#include "gtest/gtest.h"
#include <iostream>

#include "../traversal_levelorder/levelorder_traversal.h"

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

/* create fixture to initialize the data for all test cases */
class inordersuccessorbst_test: public ::testing::Test {
protected:
	virtual void SetUp() {
		root = new TreeNode(4);
		root->left = new TreeNode(2);
		root->right = new TreeNode(6);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(3);
		root->right->left = new TreeNode(5);
		root->right->right = new TreeNode(7);
	}

	// virtual void TearDown() {}
	TreeNode *root;
};


TEST_F(inordersuccessorbst_test, normal)
{
	inordersuccessorbst c;

	TreeNode *p = new TreeNode(4);
	TreeNode *res = c.inorderSuccessor(root, p);
	ASSERT_EQ(res->val, 5);
}

TEST_F(inordersuccessorbst_test, lastnode)
{
	inordersuccessorbst c;

	TreeNode *p = new TreeNode(7);
	TreeNode *res = c.inorderSuccessor(root, p);
	ASSERT_TRUE(res == nullptr);
}

TEST_F(inordersuccessorbst_test, firstnode)
{
	inordersuccessorbst c;

	TreeNode *p = new TreeNode(-10);
	TreeNode *res = c.inorderSuccessor(root, p);
	ASSERT_EQ(res->val, 1);
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
