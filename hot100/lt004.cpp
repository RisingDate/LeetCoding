//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
#define dd double
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n=nums1.size(),m=nums2.size();
		int delNum=m+n-1>>1;
		int l1=0, l2=0, r1=n-1, r2=m-1;
		int cnt1=0, cnt2=0, flag1=0, flag2=0;
		while (1) {
			bool isOod1=(r1-l1+1)&1, isOod2=(r2-l2+1)&1;
			int mid1=l1+r1>>1, mid2=l2+r2>>1;
			dd x1 = nums1[mid1], x2=nums2[mid2];
			if (isOod1) x1 = (x1 + nums1[mid1]) / 2;
			if (isOod2) x2 = (x2 + nums2[mid2]) / 2;
			if (x1 <= x2) {
				if (!isOod1) mid1++;
				if (cnt1+mid1-l1 >= delNum) {flag1=1; break;}
				cnt1 = cnt1+mid1-l1;
				l1=mid1;
				if (cnt2+r2-mid2 >= delNum) {flag2=1; break;}
				cnt2=cnt2+r2-mid2;
				r2=mid2;
			}
			else {
				if (!isOod2) mid2++;
				if (cnt1+mid2-l2 >= delNum) {flag1=2; break;}
				cnt1=cnt1+mid2-l2;
				l2=mid2;
				if (cnt2+r1-mid1 >= delNum) {flag2=2; break;}
				cnt2=cnt2+r1-mid1;
				r1=mid1;
			}
		}
		if (flag1==1) return nums1[l1+delNum-cnt1];
		if (flag1==2) return nums2[l2+delNum-cnt1];

		if (flag2==1) return nums1[r1-delNum+cnt1];
		if (flag2==2) return nums2[r2-delNum+cnt2];
	}
};
int main() {
	Solution s;
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {3,4,5};
	cout<<s.findMedianSortedArrays(nums1, nums2);
}