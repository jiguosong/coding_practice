/*
 * Array.h
 *
 *  Created on: Nov 6, 2016
 *      Author: songjiguo
 */

#ifndef ARRAY_NODE_H_
#define ARRAY_NODE_H_

#include <iostream>
#include <random>
#include <cassert>

using namespace std;

/*
 *
 *    This is the list object
 *
 * */

template<class T>
class Array
{
public:

	Array() :
			length(0), lower(0), upper(0)
	{
	}

	Array(unsigned int array_sz, T __lower, T __upper) :
			length(array_sz), lower(__lower), upper(__upper)
	{
	}

	~Array() {}

	vector<T> getUniqueArray();
	vector<T> getRandomArray();

private:
	T lower;
	T upper;
	unsigned int length;
	vector<T> array_;
};

template<class T>
vector<T> Array<T>::getUniqueArray()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<T> dist(lower, upper);

	std::set<int> myset;
	int i = 0;
	while (myset.size() < length) {
		T e = dist(gen);
		assert(e >= lower && e <= upper);
		const bool is_in = myset.find(e) != myset.end();
		if (is_in == false) {
			myset.insert(e);
			array_.push_back(e);
		}
	}

	return array_;
}

template<class T>
vector<T> Array<T>::getRandomArray()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<T> dist(lower, upper);

	for (int i = 0; i < length; ++i) {
		T e = dist(gen);
		assert(e >= lower && e <= upper);
		array_.push_back(e);
	}

	return array_;
}

#endif /* ARRAY_NODE_H_ */
