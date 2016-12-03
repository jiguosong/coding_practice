/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "buildfortress.h"

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

TEST(buildfortress, normal)
{
	buildfortress tc;
	vector<int> nums = {1,1,2,2,2,3,1,1,3,3,3};
	ASSERT_EQ(2, tc.numberofFortresstoBuild(nums));
}

TEST(buildfortress, allsame)
{
	buildfortress tc;
	vector<int> nums = {1,1,1,2,2,3,3,3,3};
	ASSERT_EQ(0, tc.numberofFortresstoBuild(nums));
}

TEST(buildfortress, allsame_down)
{
	buildfortress tc;
	vector<int> nums = {1,1,1,2,2,3,3,3,3};
	std::reverse(nums.begin(), nums.end());
	ASSERT_EQ(0, tc.numberofFortresstoBuild(nums));
}

TEST(buildfortress, zeros)
{
	buildfortress tc;
	vector<int> nums = {};
	ASSERT_EQ(0, tc.numberofFortresstoBuild(nums));
}


GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
