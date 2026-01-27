//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int l=0, mid=1 ,r;
		while (l < nums.size()) {
			mid = l+1;
			while (mid < nums.size()) {
				int targetNum = -nums[mid] - nums[l];
				if (targetNum < nums[mid]) break;
				auto r = upper_bound(nums.begin() + mid, nums.end(), targetNum) - 1;
				if (r !=nums.end() && *r == targetNum && r -nums.begin() != mid) ans.push_back({nums[l], nums[mid], *r});
				auto it = upper_bound(nums.begin() + mid, nums.end(), nums[mid]);
				if (it == nums.end()) break;
				else mid = it - nums.begin();
			}
			auto it = upper_bound(nums.begin() + l, nums.end(), nums[l]);
			if (it == nums.end()) break;
			l = it - nums.begin();
		}
		return ans;
	}
};

int main() {
	vector<int> nums = {-1,0,1,2,-1,-4};
	Solution s;
	auto ans = s.threeSum(nums);
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		vector<int> temp = *it;
		for (auto jt = temp.begin(); jt != temp.end(); ++jt) {
			printf("%d ", *jt);
		}
		putchar('\n');
	}
}