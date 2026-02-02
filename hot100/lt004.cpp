//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
#define dd double
	dd getAns(vector<int> nums) {
		int mid=nums.size()-1>>1;
		if(nums.size()&1) return nums[mid];
		else return dd(nums[mid]+nums[mid+1])/2;
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if(nums1.size()<nums2.size()) swap(nums1, nums2);
		int n=nums1.size(), m=nums2.size();
		if(!m) return getAns(nums1);
		int pos = n+m+1>>1, x=0;
		int l=0,r=n-1;
		while(l<=r) {
			int mid=l+r>>1;
			auto p =lower_bound(nums2.begin(), nums2.end(), nums1[mid]);
			int nums = mid+1 + p-nums2.begin();
			if(nums>=pos) r=mid-1, x=mid;
			else l=mid+1;
		}
		auto p = lower_bound(nums2.begin(), nums2.end(), nums1[x]);
		int nums = x + p-nums2.begin();
		dd ans=0;
		if(nums>=pos) {
			ans=nums2[pos-x-1];
			if(!(n+m&1)) {
				if(pos-x<nums2.size()&&nums2[pos-x]<nums1[x]) ans = (ans+nums2[pos-x]) / 2;
				else ans = (ans + nums1[x]) / 2;
			}
		}
		else {
			ans=nums1[x];
			if(!(n+m&1)) {
				p = lower_bound(nums2.begin(), nums2.end(), ans);
				if(x==nums1.size()-1) ans = (ans + *p) / 2;
				else if(p==nums2.end()) ans = (ans + nums1[x+1])/2;
				else ans = (ans + min(nums1[x+1], *p)) / 2;
			}
		}
		return ans;
	}
};
int main() {
	Solution s;
	vector<int> nums1 = {1};
	vector<int> nums2 = {4,5};
	cout<<s.findMedianSortedArrays(nums1, nums2);
}