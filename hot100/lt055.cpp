//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int mx = nums[0];
		for (int i = 1; i <= min(mx, n-1); i++) {
			mx=max(mx,i+nums[i]);
		}
		return mx >= n-1;
	}
};
int main() {
	Solution s;
	vector<int> nums = {1};
	cout << s.canJump(nums) << endl;
}