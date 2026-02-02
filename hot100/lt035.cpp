//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto p = lower_bound(nums.begin(), nums.end(), target);
		return p-nums.begin();
	}
};