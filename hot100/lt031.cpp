//
// Created by 17732 on 26-2-10.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n=nums.size();
		int pos=-1;
		for (int i=n-1; i>0; i--)
			if (nums[i-1]<nums[i]){ pos = i-1; break;}
		if (pos == -1) {
			for (int i=0; i<n/2; i++)
				swap(nums[i], nums[n-i-1]);
			return ;
		}

		int ed = n-1;
		for (int i=n-1; i>pos; i--)
			if (nums[i]>nums[pos]) {
				ed=i; break;
			}
		swap(nums[pos], nums[ed]);
		++pos;
		ed = n-1;
		while (pos < ed) swap(nums[pos++], nums[ed--]);
	}
};
int main() {
	Solution s;
	vector<int> nums = {2,3,1};
	s.nextPermutation(nums);
}