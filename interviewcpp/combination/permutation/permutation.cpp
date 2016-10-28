using namespace std;

#include <iostream>
#include <vector>

class permutation{
public:
	vector<vector<int>> permute(vector<int> &nums) {
		vector<vector<int>> res;
		vector<int> tmp;
		vector<bool> visited(nums.size(), false);

		if (nums.size() == 0) return res;

		permute_helper(nums, 0, visited, tmp, res);

		return res;
	}

private:
	void permute_helper(vector<int> &nums, int level, vector<bool> &visited,
						  vector<int> &tmp, vector<vector<int>> &res){
		if (tmp.size() == nums.size()) {
			res.push_back(tmp);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (visited[i] == true) continue;

			visited[i] = true;
			tmp.push_back(nums[i]);
			permute_helper(nums, i+1, visited, tmp, res);
			visited[i] = false;
			tmp.pop_back();
		}
		return;
	}

private:
	void Print(const vector<vector<int>> &v){
		for (auto &i:v) {
			for (auto &k:i) {
				cout << k;
			}
			cout << endl;
		}
	}
};


int main(int argc, char** argv) {
	cout << "CPP:permutation" << endl;

	permutation test;
	vector<int> nums {1,2,3};
	vector<vector<int>> res = test.permute(nums);

	for (auto &i:res) {
		for (auto &k:i) {
			cout << k;
		}
		cout << endl;
	}

	return 0;
}
