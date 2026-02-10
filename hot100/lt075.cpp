//
// Created by 17732 on 26-2-10.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int l=0, r=nums.size()-1, n=nums.size(), i;
		while (l<n&&nums[l]==0) ++l;
		while (r>=0&&nums[r]==2) --r;
		i=l;
		while (l<=r&&i<=r) {
			if (nums[i]==0) {
				swap(nums[i], nums[l++]);
				i = max(i, l);
			}
			else if (nums[i]==1)
				++i;
			else if (nums[i]==2)
				swap(nums[i], nums[r--]);
		}
	}
};
int main() {
	Solution s;
	vector<int> nums = {0,2,1};
	s.sortColors(nums);
	for (auto i : nums) cout << i << " ";
}