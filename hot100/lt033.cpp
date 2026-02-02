//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		int x = nums[0], pos=0;
		while (l<=r) {
			int mid = l+r>>1;
			if (nums[mid] >= x) pos = mid, l = mid + 1;
			else r = mid - 1;
		}
		l = 0, r = nums.size() - 1;
		if (target >= nums[l]) r = pos;
		else l = pos+1;
		auto p = lower_bound(nums.begin()+l, nums.begin()+r+1, target);
		if (p != nums.end() && *p == target) return int(p - nums.begin());
		return -1;
	}
};
int main() {
	Solution s;
	vector<int> nums = {5, 1, 3};
	int target = 3;
	cout << s.search(nums, target) << endl;
}