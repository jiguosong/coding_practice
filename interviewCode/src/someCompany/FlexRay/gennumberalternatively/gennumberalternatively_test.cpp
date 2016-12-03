/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "gennumberalternatively.h"

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

/*A=123 B=67894, then C = 16273894
          A=12345 B=87 , then C = 1827345
          A=1234  B=0  , then C = 10234
          */
TEST(gennumberalternatively, normal)
{
	gennumberalternatively tc;
	ASSERT_EQ(16273894, tc.produceNumber(123, 67894));
}

TEST(gennumberalternatively, normal2)
{
	gennumberalternatively tc;
	ASSERT_EQ(1827345, tc.produceNumber(12345, 87));
}

TEST(gennumberalternatively, normal3)
{
	gennumberalternatively tc;
	ASSERT_EQ(10234, tc.produceNumber(1234, 0));
}

TEST(gennumberalternatively, normal4)
{
	gennumberalternatively tc;
	ASSERT_EQ(1234, tc.produceNumber(0, 1234));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
