/* googletest unit test for C++ */

/*
 * isswapsorted.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: songjiguo
 */


/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

#include "isswapsorted.h"

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

TEST(isswapsorted, normal)
{
	isswapsorted tc;
	vector<int> nums = {1,5,3,4,2};
	ASSERT_TRUE(tc.isSwaptwoSorted(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
