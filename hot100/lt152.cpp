//
// Created by 17732 on 26-2-4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int ans = nums[0];
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
		dp[0][0] = dp[0][1] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i][0] = dp[i][1] = nums[i];
			if (nums[i]>0)
				dp[i][0] = max(nums[i], dp[i-1][0]*nums[i]),
				dp[i][1] = min(nums[i], dp[i-1][1]*nums[i]);
			else if (nums[i]<0)
				dp[i][0] = max(nums[i], dp[i-1][1]*nums[i]),
				dp[i][1] = min(nums[i], dp[i-1][0]*nums[i]);
			ans = max(ans, dp[i][1]);
			ans = max(ans, dp[i][0]);
		}
		return ans;
	}
};