/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

#include "dividearray.h"

using std::cout; 
using std::endl;
using std::vector;

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

TEST(dividearray, normal)
{
	dividearray tc;
	vector<int> nums = {15,12,9,1,23,12};
	ASSERT_TRUE(tc.isArrayDividableInEqualSums(nums));
}

TEST(dividearray, twoset)
{
	dividearray tc;
	vector<int> nums = {8, 100, 62, 29, 1, 2};
	ASSERT_TRUE(tc.isArrayDividableInEqualSums_Set(nums));
}

TEST(dividearray, twoset_fail)
{
	dividearray tc;
	vector<int> nums = {15,12,9,1,23};
	ASSERT_FALSE(tc.isArrayDividableInEqualSums_Set(nums));
}

TEST(dividearray, twoset_2)
{
	dividearray tc;
	vector<int> nums = {1,2,4,5};
	ASSERT_TRUE(tc.isArrayDividableInEqualSums_Set(nums));
}

TEST(dividearray, twoset_allzeros)
{
	dividearray tc;
	vector<int> nums = {0,0,0,0,0,0,0};
	ASSERT_TRUE(tc.isArrayDividableInEqualSums_Set(nums));
}


TEST(dividearray, twoset_getall)
{
	dividearray tc;
	vector<int> nums = {8, 100, 62, 29, 1, 2};
	vector<vector<int>> ans = tc.allArrayDividableInEqualSums_Set(nums);
	ASSERT_EQ(ans[0][0], 100);
	ASSERT_EQ(ans[0][1], 1);
	ASSERT_EQ(ans[1][0], 2);
	ASSERT_EQ(ans[1][1], 29);
	ASSERT_EQ(ans[1][2], 62);
	ASSERT_EQ(ans[1][3], 8);

	//PrintVectorVector(ans);
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
