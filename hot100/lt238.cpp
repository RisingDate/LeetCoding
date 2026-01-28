//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans = {1};
		int n = nums.size(), x=1;
		for (int i = 1; i < n; i++)
			ans.push_back(ans[i-1] * nums[i-1]);
		for (int i = n-1; i >= 0; i--) {
			ans[i] = ans[i] * x;
			x *= nums[i];
		}
		return ans;
	}
};
int main() {
	Solution s;
	vector<int> nums = {1,2,3,4};
	vector<int> ans = s.productExceptSelf(nums);
}