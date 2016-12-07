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
	Task3 s;

	std::vector<int> first;
	first.push_back(1);
	first.push_back(2);
	first.push_back(3);

	s.addLast(first);

	std::cout << s.containsSum3(6) << '\n';
	std::cout << s.containsSum3(9) << '\n';

	std::vector<int> second;
	second.push_back(4);
	s.addLast(second);

	std::cout << s.containsSum3(9) << '\n';

}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
