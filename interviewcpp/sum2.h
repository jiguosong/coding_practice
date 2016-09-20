class Solution_twoSum {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> m;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			m[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int t = target - nums[i];
			if (m.count(t) && m[t] != i) {
				res.push_back(i);
				res.push_back(m[t]);
				break;
			}
		}
		return res;
	}

public:
	void test(){
		cout << "CPP:twoSum" << endl;
		vector<int> input {0, 1 , 2, 3, 4, 5, 6};
		vector<int> res(2);
		res = this->twoSum(input, 8);
		cout << res[0] << endl;
		cout << res[1] << endl;
	}

};
