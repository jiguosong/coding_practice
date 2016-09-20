using namespace std;

class Solution_combination{
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> tmp;

		if (n == 0 || n < k) return res;

		combine_helper(n, k, 1, tmp, res);

		return res;
	}

private:
	void combine_helper(int n, int k, int level, vector<int> &tmp, vector<vector<int>> &res){
		if (tmp.size() == k) {
			res.push_back(tmp);
			return;
		}

		for (int i = level; i <= n; i++) {
			tmp.push_back(i);
			combine_helper(n, k, i+1, tmp, res);
			tmp.pop_back();
		}
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

public:
	void test(){
		cout << "CPP: combination" << endl;
		vector<vector<int>> result;
		int n = 4;
		int k = 2;
		result = combine(n, k);
		Print(result);
	}
};
