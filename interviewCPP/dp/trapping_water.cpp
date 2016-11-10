/*
 * mostwater.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <vector>
#include <assert.h>
#include <limits.h>
#include <array>


class trapping_water {
public:
	virtual void run() = 0;
	virtual ~trapping_water(){};
};


////////////////
// thin wall version
///////////////
class thin_wall : public trapping_water {
public:
	void run() override {
		vector<int> height = {1,2,3,4,5};
		int res = 0;

		res = maxArea(height);
		cout << res << endl;
	}

	static thin_wall &instance() {
		static thin_wall *p = new thin_wall;
		return *p;
	}

	~thin_wall(){};
private:
	thin_wall(){};
	thin_wall(const thin_wall &other);
	const thin_wall &operator=(const thin_wall &other);

	int maxArea(vector<int>& height);
};

int thin_wall::maxArea(vector<int>& height) {
	int left = 0;
	int right = height.size()-1;

	int maxwater = 0;

	while(left < right) {
		int w = right - left;
		int h = min(height[left], height[right]);
		maxwater = max(maxwater, w*h);
		if(height[left] < height[right]) ++left;
		else --right;
	}
	return maxwater;
}


////////////////
// elevation_map version
///////////////
class elevation_map : public trapping_water {
public:
	void run() override {
		int res;
		int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
		int n = sizeof(A)/sizeof(A[0]);
		res = trap(A, n);
		cout << endl;
		cout << res << endl;
	}

	static elevation_map &instance() {
		static elevation_map *p = new elevation_map;
		return *p;
	}

	~elevation_map(){};

private:
	elevation_map(){};
	elevation_map(const elevation_map &other);
	const elevation_map &operator=(const elevation_map &other);
	int trap(int A[], int n);
};

int elevation_map::trap(int A[], int n) {
	int maxleft[n];
	int maxright[n];
	std::fill_n(maxleft, n, 0);
	std::fill_n(maxright, n, 0);

	for(int i = 1; i < n; ++i) maxleft[i] = max(maxleft[i-1], A[i-1]);
	for(int i = n-2; i >= 0; --i) maxright[i] = max(maxright[i+1], A[i+1]);

	int totalwater = 0;
	for(int i = 0; i < n; i++) {
		int tmp = min(maxleft[i], maxright[i]);
		if(tmp > A[i]) totalwater += tmp - A[i];
	}

	return totalwater;
}

class solution {
public:
	static trapping_water *trapping_water_solution (const string &name) {
		if(name == "thin wall") {
			trapping_water &p = thin_wall::instance();
			return &p;
		}

		if(name == "elevation map") {
			trapping_water &p = elevation_map::instance();
			return &p;
		}

		return NULL;
	}
};

int main(int argc, char **argv) {

	solution solution_fac;

	solution_fac.trapping_water_solution("thin wall")->run();
	solution_fac.trapping_water_solution("elevation map")->run();


}

