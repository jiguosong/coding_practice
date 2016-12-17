#ifndef binaryindextree_H_
#define binaryindextree_H_

#include <vector>
using std::vector;

class binaryindextree {
public:
	void dummy();
	binaryindextree(vector<int> &nums);
	void update(int i, int val);
	int sumRange(int i, int j);
	int getSum(int i);
private:
	vector<int> nums_;
	vector<int> bits_;
	int sz_;
};

#endif
