//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	static bool cmp(pair<int,int> a,pair<int,int> b) {return a.first>b.first;}
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<pair<int, int>> cnt;
		vector<int> ans;
		unordered_map<int, int> mp;
		for (int i=0;i<nums.size();i++) {
			if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = 1;
			else mp[nums[i]]++;
		}
		for (auto x:mp)
			cnt.push_back({x.second,x.first});
		sort(cnt.begin(), cnt.end(), cmp);
		for (int i=0;i<k;i++) ans.push_back(cnt[i].second);
		return ans;
	}
};