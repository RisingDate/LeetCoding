//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto p = lower_bound(nums.begin(), nums.end(), target);
		auto q = upper_bound(nums.begin(), nums.end(), target);
		if (p==nums.end() || *p!=target) return {-1,-1};
		return {int(p-nums.begin()), int(q-nums.begin()-1)};
	}
};