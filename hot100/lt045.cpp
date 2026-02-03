//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int ans=0;
		int s=0, t=0;
		while (t<nums.size()-1) {
			int x=0;
			for (int i=s;i<=t;i++) x=max(x, nums[i]+i);
			s=t+1, t=x;
			++ans;
		}
		return ans;
	}
};