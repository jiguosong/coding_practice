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

	vector<int> A = {1,3,-3};
	ASSERT_EQ(6, tc.solution(A));
}

TEST(Task2, normal2)
{
	Task2 tc;

	vector<int> A = {4,3,2,5,1,1};
	ASSERT_EQ(4, tc.solution(A));
}

TEST(Task2, normal3)
{
	Task2 tc;

	vector<int> A = {0};
	ASSERT_EQ(0, tc.solution(A));
}

TEST(Task2, overflow)
{
	Task2 tc;
	vector<int> A = {std::numeric_limits<int>::max(), 2,3,4,-100, std::numeric_limits<int>::min(),1, -6, 2, std::numeric_limits<int>::min(),-2};
	ASSERT_EQ(0, tc.solution(A));
}


TEST(Task2, underflow)
{
	Task2 tc;
	vector<int> A = {std::numeric_limits<int>::min(), 2,3,4,-100, std::numeric_limits<int>::max(),1, -6, 2, std::numeric_limits<int>::min(),-2};
	ASSERT_EQ(0, tc.solution(A));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
