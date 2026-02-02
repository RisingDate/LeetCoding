//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		int x = nums[0], pos=0;
		while (l<=r) {
			int mid = l+r>>1;
			if (nums[mid] >= x) pos = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (pos+1 == nums.size()) return nums[0];
		else return nums[pos+1];
	}
};