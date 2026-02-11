//
// Created by 17732 on 26-2-11.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> v1 = vector<int>(28, 0);
	vector<int> v2 = vector<int>(28, 0);
	vector<int> v3;
	void work(int num, vector<int>& v) {
		int cnt=0;
		while (num) {
			if (num & 1) v[cnt]++;
			num>>=1,++cnt;
		}
	}
	int findDuplicate(vector<int>& nums) {
		int n=nums.size();
		for (int i=1;i<n;i++) work(i, v1);
		for (int i=0; i<n; i++) work(nums[i], v2);
		for (int i=0; i<v2.size(); i++)
			if (v2[i] > v1[i]) v3.push_back(1);
			else v3.push_back(0);
		int ans=0;
		for (int i=v3.size()-1; i>=0; i--) {
			if (v3[i]) ans++;
			if (i) ans<<=1;
		}
		return ans;
	}
};
int main() {
	Solution s;
	vector<int> v = {1,3,4,2,2};
	int ans = s.findDuplicate(v);
	cout<< ans << endl;
}