/*
 * Task1.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#include "Task1.h"
#include <algorithm>
#include <iostream>

#include <unordered_map>
#include <queue>

using namespace std;

int Task1::kthMostCommon(const std::vector<int>& a, int k) {
	cout << "task1..." << endl;

	//if(k <= 0) return -1;
	//if(a.empty()) return -1;

	if(a.empty() || k <= 0) throw std::logic_error("invalid input");
	if(a.size() < k) throw std::logic_error("invalid input");

	std::unordered_map<int, int> m;
	std::priority_queue<std::pair<int, int>> q;

	for (auto e : a) ++m[e];
	for (auto it : m) q.push({it.second, it.first});
	for (int i = 0; i < k-1; ++i) q.pop();

	int res = q.top().second;
	return res;


	//vector<int> res;
	//for (int i = 0; i < k-1; ++i) {
		//res.push_back(q.top().second);
		//cout << q.top().second << endl;
//		q.pop();
	//}

	//int res = q.top().second;
	//return res;

	//return res[k-1];
}




/*
#include <vector>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>

class Common
{
public:
    static int kthMostCommon(const std::vector<int>& a, int k)
    {
        //throw std::logic_error("Waiting to be implemented");

        // assumption: vector a is not empty, and k > 0
        // TODO: really need define what to return if the input is not valid
        if(a.empty() || k <= 0) throw std::logic_error("invalid input");

        std::unordered_map<int, int> m;
	    std::priority_queue<std::pair<int, int>> q;

	    for (auto e : a) ++m[e];
	    for (auto it : m) q.push({it.second, it.first});
	    for (int i = 0; i < k-1; ++i) q.pop();

	    int res = q.top().second;
	    return res;
    }
};

#ifndef RunTests
int main()
{
    std::vector<int> input;
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(5);
    input.push_back(4);
    input.push_back(5);

    int x = Common::kthMostCommon(input, 2);
    std::cout << x;
}
#endif*/
