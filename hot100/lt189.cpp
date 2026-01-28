//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void reverse(vector<int>& nums, int s, int t) {
		int mid=s+t>>1;
		for(int i=s;i<=mid;i++) swap(nums[i],nums[t-i+s]);
	}
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		reverse(nums, 0, n-1);
		reverse(nums, 0, k-1);
		reverse(nums, k, n-1);
	}
};
int main() {
	Solution s;

}