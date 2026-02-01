//
// Created by 17732 on 26-2-1.
//
#include <bits//stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	void dfs(int x, vector<int> nums, vector<int> temp) {
		if (x>=nums.size()) {
			res.push_back(temp);
			return ;
		}
		temp.push_back(nums[x]);
		dfs(x+1, nums, temp);
		temp.pop_back();
		dfs(x+1, nums, temp);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		dfs(0, nums, {});
		return res;
	}
};