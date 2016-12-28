/* googletest unit test for C++ */

#include "gtest/gtest.h"

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>

#include <set>    // multiset is also defined here
#include <map>    // multimap is also defined here
#include <unordered_set>  // unordered_multiset is also defined here
#include <unordered_map>  // unordered_multimap is also defined here

/*
 * stack          - use standard containers std::vector, std::deque and std::list
 * queue          - use standard containers std::deque and std::list
 * priority_queue - use standard containers std::vector and std::deque
 * */
#include <stack>       // stack
#include <queue>       // queue + priority_queue

#include <algorithm>
#include <random>
#include <string>
#include <memory>
#include <random>

using namespace std;

#include "longestbinarygap.h"

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

template<class T>
bool CompareVectorVector(const vector<T> &v1, const vector<T> &v2)
{
	if (v1.size() != v2.size())
		return false;

	std::multiset<T> s1(v1.begin(), v1.end());
	std::multiset<T> s2(v2.begin(), v2.end());
	std::vector<T> v3;
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
			std::back_inserter(v3));
	return (v3.size() == v1.size());
}

static int getRandom(int lower, int upper)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(lower, upper);
	return dist(gen);
}

// first way to generate random string of len
string getRandomString(int len)
{
	string str(len, ' ');
	for (int i = 0; i < len; ++i) {
		int randchar =
				getRandom(0, std::numeric_limits<int>::max()) % (26 + 26 + 10);
		if (randchar < 26) {
			str[i] = 'a' + randchar;
		} else if (randchar < 26 + 26) {
			str[i] = 'A' + randchar - 26;
		} else {
			str[i] = '0' + randchar - 26 - 26;
		}
	}

	return str;
}

// second way to generate random string of len
string gen_random(const int len)
{
	static const char alphanum[] = "0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

	string str(len, ' ');
	for (int i = 0; i < len; ++i) {
		str[i] =
				alphanum[getRandom(0, std::numeric_limits<int>::max()) % (sizeof(alphanum) - 1)];
	}

	return str;
}

TEST(longestbinarygap, normal1)
{
	longestbinarygap tc;

	int ans = tc.longestBinGap(3);
	ASSERT_EQ(0, ans);
}

TEST(longestbinarygap, normal2)
{
	longestbinarygap tc;

	int ans = tc.longestBinGap(9);
	ASSERT_EQ(2, ans);
}

TEST(longestbinarygap, normal3)
{
	longestbinarygap tc;

	int ans = tc.longestBinGap(529);
	ASSERT_EQ(4, ans);
}

TEST(longestbinarygap, normal4)
{
	longestbinarygap tc;

	int ans = tc.longestBinGap(20);
	ASSERT_EQ(1, ans);
}

TEST(longestbinarygap, normal5)
{
	longestbinarygap tc;

	int ans = tc.longestBinGap(15);
	ASSERT_EQ(0, ans);
}

TEST(longestbinarygap, normal6)
{
	longestbinarygap tc;

	int ans = tc.longestBinGap(1041);
	ASSERT_EQ(5, ans);
}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
