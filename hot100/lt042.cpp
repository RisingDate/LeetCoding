//
// Created by 17732 on 26-1-27.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		vector<int> maxHeight(height.size(), 0);
		for (int i = height.size() - 1; i >= 0; i--)
			if (i == height.size() - 1) maxHeight[i] = height[i];
			else maxHeight[i] = max(maxHeight[i+1], height[i]);
		int leftMaxHeight = 0;
		for (int i=0; i < height.size(); i++) {
			leftMaxHeight = max(leftMaxHeight, height[i]);
			ans += min(leftMaxHeight, maxHeight[i]) - height[i];
		}
		return ans;
	}
};
int main() {
	vector<int> height = {4,2,0,3,2,5};
	Solution s;
	cout << s.trap(height) << endl;
}