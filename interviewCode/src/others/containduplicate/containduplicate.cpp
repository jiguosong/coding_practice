
#include "containduplicate.h"

#include <unordered_map>

void containduplicate::dummy()
{
}

bool containduplicate::containDuplicates(vector<int> &nums)
{
	std::unordered_map<int, int> map;

	for(auto e: nums) {
		if (map.count(e)) return true;
		++map[e];
	}
	return false;
}
