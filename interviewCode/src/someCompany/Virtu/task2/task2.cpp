/*




*/

#include "task2.h"
#include <algorithm>
#include <iostream>

using namespace std;

void task2::dummy() 
{
}

int task2::solution(vector<int> &A)
{
	int max = A[0];
	if(max > 5000) return 0;

	vector<int> B;
	for(int i = 1; i < A.size(); ++i) B.push_back(A[i]);

	std::sort(B.begin(), B.end());

	int cnt = 0;

	for(auto e:B) {
		max += e;
		if(max > 5000) break;
		++cnt;
	}

	return cnt;

}
