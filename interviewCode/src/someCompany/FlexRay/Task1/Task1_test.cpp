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

	vector<int> A = { 1,3,2,1};
	vector<int> B = { 4,2,5,3,2};
	ASSERT_EQ(2, tc.solution(A, B));
}

TEST(Task1, normal2)
{
	Task1 tc;

	vector<int> A = { 2,1};
	vector<int> B = { 3,3};
	ASSERT_EQ(-1, tc.solution(A, B));
}

TEST(Task1, normal3)
{
	Task1 tc;

	vector<int> A = { 3,2,5,6,87,2,4,5,54};
	vector<int> B = { 1,1,1,1,1,1,1,1,1,1,4};
	ASSERT_EQ(4, tc.solution(A, B));
}

TEST(Task1, normal4)
{
	Task1 tc;

	vector<int> A = { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,54,100};
	vector<int> B = { 3,2,5,6,87,2,4,12,54};

	ASSERT_EQ(54, tc.solution(A, B));
}

TEST(Task1, normal5)
{
	Task1 tc;

	vector<int> A = { 1,1,1,1,1,1,1,1,1,1,1,1,54,100};
	vector<int> B = { 3,2,5,6,2,3,53,5,3,6,67,567,2,2,87,2,4,12,54};

	ASSERT_EQ(54, tc.solution(A, B));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
