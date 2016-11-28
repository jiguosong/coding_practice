/* googletest unit test for C++ */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>

#include "parsestr2tree.h"

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

TEST(parserstr2tree, normal)
{
	parserstr2tree tc;

	//string s = "{ name:a, children:[{name:aa, children:[{children:[{name:aaaa}], name:aaa}, {name:aab}]}, {name:ab}]}";
	//string ss = "{children:[{lefts}, {rights}], name:roots}";
	//TreeNode *ans = parserstr2tree(s);

}

GTEST_API_ int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
