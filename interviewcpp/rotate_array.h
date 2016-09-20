class Solution_Rotate_Array{
public:
	void rotate(vector<int> &nums, int k) {
		if (nums.empty()|| k <= 0) return;

		int n = nums.size();
		if (k > n) k = k%n;

		reverse(nums, 0, n-k-1);
		reverse(nums, n-k, n-1);
		reverse(nums, 0, n-1);
	}

	void reverse(vector<int> &nums, int l, int r){
		int tmp;
		while (l < r) {
			tmp = nums[l];
			nums[l] = nums[r];
			nums[r] = tmp;
			l++;
			r--;
		}
	}

	void test(){
		cout << "CPP:rotate array test" << endl;

		vector<int> aaa {1,2,3,4,5,6,7};
		int k = 3;

		rotate(aaa, k);

		for (int i = 0; i < aaa.size(); i++)
			cout << aaa[i] ;
		cout << endl;
	}
};
