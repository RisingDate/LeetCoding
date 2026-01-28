//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end(), cmp);
		int n = intervals.size();
		int l = intervals[0][0], r = intervals[0][1];
		for (int i = 1; i < n; i++) {
			if (intervals[i][0] <= r) r = max(r, intervals[i][1]);
			else {
				ans.push_back({l, r});
				l = intervals[i][0];
				r = intervals[i][1];
			}
		}
		ans.push_back({l, r});
		return ans;
	}
};
int main() {
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	Solution s;
	auto ans = s.merge(intervals);
}