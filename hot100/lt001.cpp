//
// Created by 17732 on 26-1-14.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct node {
		int val,idx;
	};
	static bool cmp(const node& a, const node& b) {
		return a.val < b.val;
	}
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<node> newNums;
		for (int i = 0; i < nums.size(); i++) {
			newNums.push_back({nums[i], i});
		}
		sort(newNums.begin(), newNums.end(), cmp);
		for (int i=0; i<newNums.size(); i++) {
			auto t = lower_bound(newNums.begin() + i+1,
				newNums.end(), node({target - newNums[i].val, 0}), cmp);
			if (t != newNums.end() && t->val == target - newNums[i].val)
				return {newNums[i].idx, t->idx};

		}
		return {0, 0};
	}
};

int main() {
	vector<int> nums = {3,2,3};
	Solution s;
	vector<int> res = s.twoSum(nums, 6);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}