/*




 */

// http://stackoverflow.com/questions/7843048/finding-the-closest-fibonacci-numbers#7843192

#include "task1.h"

#include <iostream>
#include <algorithm>

using namespace std;
void task1::dummy()
{
}


static void getFibonacci(int target, vector<unsigned long> &fibs)
{
	int c, first = 0, second = 1, next;
	int n = 50;
	for (c = 0; c < n; c++) {
		if (c <= 1)
			next = c;
		else {
			next = first + second;
			first = second;
			second = next;
		}
		if (next > target)
			break;
		fibs.push_back(next);
	}
}

int task1::solution(int X)
{
	// if  5 N^2 + 4 or 5N^2 – 4 is sqaure number

	vector<unsigned long> fibos;
	getFibonacci(1000000, fibos);

	for (auto a : fibos)
		cout << a << " \n";

	int left = 0;
	int right = fibos.size();
	int mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (fibos[mid] == X)
			return 0;
		else if (fibos[mid] < X)
			left = mid + 1;
		else
			right = mid - 1;
	}

	int steps = std::min(std::abs(X-fibos[left]), std::abs(X-fibos[right]));

	return steps;
}
