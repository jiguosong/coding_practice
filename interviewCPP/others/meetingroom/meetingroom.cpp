/*
 * meetingroom.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "meetingroom.h"

#include <map>

#include <iostream>
#include <algorithm>

using std::map;

int meetingroom_sol::minMeetingRooms(vector<Interval>& intervals)
{
    vector<int> starts, ends;
	int res = 0, endpos = 0;
	for (auto a : intervals) {
		starts.push_back(a.s);
		ends.push_back(a.e);
	}
	//sort(starts.begin(), starts.end());
	//sort(ends.begin(), ends.end());

	for (int i = 0; (size_t)i < intervals.size(); ++i) {
		if (starts[i] <= ends[endpos]) ++res;
		else ++endpos;
	}
	return res;
}
