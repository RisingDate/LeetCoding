//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int n = matrix.size(), m = matrix[0].size();
		int r = m-1;
		for (int i = 0; i < m; i++)
			if (matrix[0][i] > target) {
				r = i - 1;
				break;
			}
		for (int i = 0; i < n; i++) {
			if (matrix[i][0] > target) break;
			auto p = lower_bound(matrix[i].begin(), matrix[i].begin()+r, target);
			if (*p == target) return true;
		}
		return false;
	}
};
int main() {
	Solution s;
	vector<vector<int> > matrix = {{-1,3}};
	int target = 3;
	cout << s.searchMatrix(matrix, target);
}