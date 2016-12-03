/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "containsKnumbers.h"

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

TEST(containsKnumbers, normal)
{
	containsKnumbers tc;
	vector<int> nums = {1,1,2,3,3};
	int K = 3;
	ASSERT_TRUE(tc.isContainsAllKNumbers(nums, K));
	ASSERT_TRUE(tc.solution(nums, K));
}

TEST(containsKnumbers, failcase)
{
	containsKnumbers tc;
	vector<int> nums = {1,1,3};
	int K = 2;
	ASSERT_FALSE(tc.isContainsAllKNumbers(nums, K));
	ASSERT_FALSE(tc.solution(nums, K));
}

TEST(containsKnumbers, toosmall)
{
	containsKnumbers tc;
	vector<int> nums = {1,1,3};
	int K = 20;
	ASSERT_FALSE(tc.isContainsAllKNumbers(nums, K));
	ASSERT_FALSE(tc.solution(nums, K));
}

TEST(containsKnumbers, allsame)
{
	containsKnumbers tc;
	vector<int> nums = {1,1,1,1,1,1,1,1};
	int K = 3;
	ASSERT_FALSE(tc.isContainsAllKNumbers(nums, K));
	ASSERT_FALSE(tc.solution(nums, K));
}


TEST(containsKnumbers, largevariance)
{
	containsKnumbers tc;
	vector<int> nums = {-100,-80,1,1,2,3,10,100, 200, 200};
	int K = 3;
	ASSERT_TRUE(tc.isContainsAllKNumbers(nums, K));
	//ASSERT_TRUE(tc.solution(nums, K));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
