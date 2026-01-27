//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int cnt = 0;
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] == 0) ++cnt;
			else if (cnt) swap(nums[i], nums[i-cnt]);
		}
	}
};
int main() {
	Solution s;
	vector<int> nums = {1,2,3,0,4,0,5,6,7,8,9};
	s.moveZeroes(nums);
}