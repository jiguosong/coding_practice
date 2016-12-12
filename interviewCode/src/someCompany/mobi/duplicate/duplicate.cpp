

#include "duplicate.h"

//Question:
//
//You are given an array of integers. Each integer in the array has value from 1 to 32,000, inclusive.
//The array may contain duplicate entries. You may assume that each entry appears in the array no more than twice.
//With only 4KB of memory available on your computer, write a function print_duplicates that would print all duplicate elements in the array?

// you may assume that arr and length are initialized in this section. length is the number of elements in arr
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned int* arr; // each entry in arr is between 1 and 32000
unsigned int length;

static void print_bin(int n)
{
	while (n) {
		if (n & 1)
			printf("1");
		else
			printf("0");
		n >>= 1;
	}
}

//#define SZ 10

void duplicate::print_duplicates() {
// write your code here.

	unsigned int myArray[10] = {1,2,3,31998,4,5,1,3,5,31998};
	//unsigned int myArray[10] = {1,2,3,4,5,6,7,8,9,10};
	arr = myArray;
	length = sizeof(myArray)/sizeof(myArray[0]);
	assert(arr);  	// check if arr is initialized somewhere
	assert(length == 10); // check if length is valid

    /*	idea: use integer bits to represent 1~32000.This requires 4000KB memory (less than 4096K)*/
	int bits[1000] = {0};
	for(int i = 0; i < 1000; ++i) bits[i] = 0xFFFF;
	//memset(bits, 1, 1000*4);

	printf("\n");
	for(int i = 0; i < length; ++i) {
		int tmp = *(arr+i);
		//printf("\ntmp is %d \n", tmp);
		int array_idx = (tmp-1)%32;
		int array_off = (tmp-1)/32;
		int pos = 1 << array_idx;
		//print_bin(pos);
		//printf("\narray_idx is %d\n", array_idx);
		//printf("array_group is %d\n", array_off);
		//printf("before XOR:"); print_bin(bits[array_off]);
		bits[array_off] ^= pos;     // use XOR to zero out the duplicated bits (or set the duplicate up)
		//printf(" after XOR:"); print_bin(bits[array_off]);
	}

	int duplicate = 0;
	for(int i = 0; i < 1000; ++i) {
		int tmp = bits[i];
		int idx = 1;
		while(tmp) {
			//printf("tmp is %d\n", tmp);
			if ((tmp & 1) == 0) {
				duplicate = 1;
				printf("%d \n", i*32+idx);
			}
			tmp >>= 1;
			++idx;
		}
	}

	if (!duplicate) printf("could not find duplicated\n");

}



