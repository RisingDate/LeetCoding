//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		vector<int> sums;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (!i) sums.push_back(nums[i]);
			else sums.push_back(nums[i] + sums[i-1]);
			if (mp.find(sums[i]) != mp.end()) mp[sums[i]]++;
			else mp[sums[i]] = 1;
		}
		for (int i = 0; i < nums.size(); i++) {
			int val = 0;
			if (i) val = sums[i-1];
			if (mp.find(k + val) != mp.end()) ans+=mp[k+val];
			mp[sums[i]]--;
		}
		return ans;
	}
};
int main() {
	Solution s;
}