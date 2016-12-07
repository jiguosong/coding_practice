/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "Task1.h"

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

TEST(Task1, normal)
{
	Task1 tc;
	vector<int> nums = {5,4,3,2,1,5,4,3,2,5,4,3,5,4,5};
	int k = 2;
	ASSERT_EQ(4, tc.kthMostCommon(nums, k));
}

TEST(Task1, normal2)
{
	Task1 tc;
	vector<int> nums = {5};
	int k = 1;
	ASSERT_EQ(5, tc.kthMostCommon(nums, k));
}

TEST(Task1, normal3)
{
	Task1 tc;
	vector<int> nums = {5};
	int k = 10;
	ASSERT_EQ(5, tc.kthMostCommon(nums, k));
}


TEST(Task1, normal4)
{
	Task1 tc;
	vector<int> nums = {5,5,5,5,5,5,5,5,5,5};
	int k = 4;
	ASSERT_EQ(5, tc.kthMostCommon(nums, k));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
