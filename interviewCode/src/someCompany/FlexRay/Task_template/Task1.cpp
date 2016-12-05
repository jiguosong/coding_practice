/*
 * Task1.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "Task1.h"
#include <algorithm>
#include <iostream>
using namespace std;

/*
A zero-indexed array A consisting of N integers is given. An equilibrium index of this array is any integer P such that 0 ≤ P < N and the sum of elements of lower indices is equal to the sum of elements of higher indices, i.e.

    A[0] + A[1] + ... + A[P−1] = A[P+1] + ... + A[N−2] + A[N−1].

Sum of zero elements is assumed to be equal to 0. This can happen if P = 0 or if P = N−1.
*/
int Task1::solution(vector<int> &A) {
	if(A.empty()) return -1;

	cout << "sdfds" << endl;
	int sz = A.size();
	vector<long long> left(sz, 0);
	vector<long long> right(sz, 0);

	left[0] = 0;
	right[sz-1] = 0;

	for(int i = 1; i < sz; ++i) left[i] = left[i-1] + A[i-1];
	for(int i = sz-2; i >= 0; --i) right[i] = right[i+1] + A[i+1];

	for(int i = 0; i < sz; ++i) if(left[i] == right[i]) return i;
	return -1;
}


int Task1::solution2(vector<int> &A) {
	if(A.empty()) return -1;

	int sz = A.size();

	// to handle overflow, there are 2 approaches (not mention safeint and x86 instruction)
	// 1) use long long
/*	long long left = 0;
	long long right = 0;
	for(int e : A) right += static_cast<long long> (e);*/

	// 2) return the error
	int left = 0;
	int right = 0;
	for(int e : A) {
		if(right > 0 && e > std::numeric_limits<int>::max() - right) {
			cerr << "overflow, return -1" << endl;
			return -1;
		} else if(right < 0 && e < std::numeric_limits<int>::min() - right) {
			cerr << "underflow, return -1" << endl;
			return -1;
		} else {
			right += e;
		}
	}

	for(int i = 0; i < sz; ++i) {
		right -= A[i];
		if(right == left) return i;
		left += A[i];
	}

	return -1;
}

/*

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::vector<size_t> equilibrium(T first, T last)
{
    typedef typename std::iterator_traits<T>::value_type value_t;

    value_t left  = 0;
    value_t right = std::accumulate(first, last, value_t(0));
    std::vector<size_t> result;

    for (size_t index = 0; first != last; ++first, ++index)
    {
        right -= *first;
        if (left == right)
        {
            result.push_back(index);
        }
        left += *first;
    }
    return result;
}

template <typename T>
void print(const T& value)
{
    std::cout << value << "\n";
}
*/

 /*
int main()
{
    const int data[] = { -7, 1, 5, 2, -4, 3, 0 };

    std::vector<size_t> indices(equilibrium(data, data + 7));

    std::for_each(indices.begin(), indices.end(), print<size_t>);
}*/
