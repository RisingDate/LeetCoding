//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> ans(temperatures.size(), 0);
		stack<int> st;
		for (int i = 0; i < temperatures.size(); i++) {
			if (st.empty()) st.push(i);
			else {
				while (!st.empty() &&temperatures[st.top()]<temperatures[i]) {
					ans[st.top()] = i - st.top();
					st.pop();
				}
				st.push(i);
			}
		}
		while (!st.empty()) {
			ans[st.top()] = 0;
			st.pop();
		}
		return ans;
	}
};