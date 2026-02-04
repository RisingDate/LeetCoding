//
// Created by 17732 on 26-2-4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		vector<bool> dp(200*102, 0);
		int target = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j=target; j >=0; j--) if (dp[j]) dp[j+nums[i]] = true;
			target += nums[i];
			dp[nums[i]] = true;
		}
		if (target&1 || !dp[target/2]) return false;
		return true;
	}
};
int main() {
	Solution s;
	vector<int> nums = {1,5,11,3};
	cout<<s.canPartition(nums);
}