using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

class count_smalestNumber {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
    };
    int insert(Node *&root, int v) {
        if (!root) return (root = new Node(v, 0)), 0;
        if (root->val > v) return root->smaller++, insert(root->left, v);
        else return insert(root->right, v) + root->smaller + (root->val < v ? 1 : 0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};

int main(){
  		cout << "CPP:longestPalindrome" << endl;
  		vector<int> nums = {1,2,1};

  		count_smalestNumber test;

  		vector<int> result = test.countSmaller(nums);
  		cout << result[0] << endl;
  		return 0;
  	}

