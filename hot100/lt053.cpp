//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int> &nums) {
		int minn = 0, ans = -2e9;
		for (int i = 0; i < nums.size(); i++) {
			if (i) nums[i] += nums[i - 1];
			ans = max(ans, nums[i] - minn);
			minn = min(minn, nums[i]);
		}
		return ans;
	}
};

int main() {
	vector<int> nums = {-2, -1};
	Solution s;
	cout << s.maxSubArray(nums) << endl;
}
