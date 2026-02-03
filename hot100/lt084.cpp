//
// Created by 17732 on 26-2-3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n=heights.size();
		stack<int> st;
		vector<int> squareL(n,0);
		vector<int> squareR(n,0);
		for (int i = 0; i < n; i++) {
			while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
			int l = -1;
			if (!st.empty()) l = st.top();
			squareL[i] = (i-l)*heights[i];
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = n-1; i >= 0; i--) {
			while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
			int r = n;
			if (!st.empty()) r = st.top();
			squareR[i] = (r-i)*heights[i];
			st.push(i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans,squareL[i]+squareR[i]-heights[i]);
		return ans;
	}
};
int main() {
	Solution s;
	vector<int> heights = {0,9};
	int ans = s.largestRectangleArea(heights);
	cout << ans << endl;
}