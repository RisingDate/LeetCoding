//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	struct node {
		int val;
		int idx;
	};
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<node> dq;
		for (int i = 0; i < nums.size(); i++) {
			while (!dq.empty() && (dq.front().val < nums[i] || dq.front().idx <= i-k))
				dq.pop_front();
			while (!dq.empty() && dq.back().val <= nums[i]) dq.pop_back();
			dq.push_back({nums[i], i});
			if (i >= k - 1) ans.push_back(dq.front().val);
		}
		return ans;
	}
};
int main() {
	Solution s;
	vector<int> nums = {1,3,1,2,0,5};
	int k = 3;
	s.maxSlidingWindow(nums, k);
}