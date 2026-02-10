//
// Created by 17732 on 26-2-10.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int res = nums[0],cnt=0;
        for (int i=0; i<nums.size(); i++) {
        	if (!cnt) res = nums[i];
	        if (res==nums[i]) cnt++;
        	else cnt--;
        }
		return res;
	}
};