/*
 * median_2sortedarray.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "median_2sortedarray.h"
#include <iostream>
#include <climits>

double median_2sortedarray::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int total = nums1.size() + nums2.size();
	if((total%2) == 1) {  // odd
		return findKth(nums1, 0, nums2, 0, total/2+1);
	} else {                // even
		double t1 = findKth(nums1, 0, nums2, 0, total/2);
		double t2 = findKth(nums1, 0, nums2, 0, total/2+1);
		return (double)(t1+t2)/2;
	}
}

double median_2sortedarray::findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k)
{
	if(k <= 0 || (size_t)k > nums1.size() + nums2.size()) return 0;

	if(k == 1) return std::min(nums1[start1], nums2[start2]);
	if((size_t)start1 >= nums1.size()) return nums2[start1+k-1];
	if((size_t)start2 >= nums2.size()) return nums1[start2+k-1];

	int mid1 = start1+k/2-1;
	int mid2 = start2+k/2-1;

	int val1 = ((size_t)mid1 < nums1.size()) ? nums1[mid1] : INT_MAX;
	int val2 = ((size_t)mid2 < nums2.size()) ? nums2[mid2] : INT_MAX;

	if(val1 < val2) return findKth(nums1, mid1+1, nums2, start2, k-k/2);
	else return findKth(nums1, start1, nums2, mid2+1, k-k/2);

}

