/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "Task3.h"

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

TEST(Task3, normal)
{
	Task3 tc;

	int A = 4;
	int B = 17;
	ASSERT_EQ(3, tc.solution(A, B));
}

TEST(Task3, normal2)
{
	Task3 tc;

	int A = 4;
	int B = -17;
	ASSERT_EQ(0, tc.solution(A, B));
}

TEST(Task3, normal3)
{
	Task3 tc;

	int A = 40;
	int B = 17;
	ASSERT_EQ(0, tc.solution(A, B));
}

TEST(Task3, normal4)
{
	Task3 tc;

	int A = 0;
	int B = 17;
	ASSERT_EQ(5, tc.solution(A, B));
}


TEST(Task3, normal5)
{
	Task3 tc;

	int A = -10;
	int B = 1;
	ASSERT_EQ(2, tc.solution(A, B));
}

TEST(Task3, normal6)
{
	Task3 tc;

	int A = -10;
	int B = 0;
	ASSERT_EQ(1, tc.solution(A, B));
}

TEST(Task3, normal7)
{
	Task3 tc;

	int A = 5;
	int B = 5;
	ASSERT_EQ(0, tc.solution(A, B));
}

TEST(Task3, normal8)
{
	Task3 tc;

	int A = 4;
	int B = 4;
	ASSERT_EQ(1, tc.solution(A, B));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
