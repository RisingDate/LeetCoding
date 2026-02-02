//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<string>> ans;
	vector<bool> col, a1, a2;
	void dfs(int x, int n, vector<string> tmp) {
		if (x==n) {
			ans.push_back(tmp);
			return;
		}
		string s = string(n, '.');
		for (int i=0; i<n ;i++) {
			if (!col[i]&&!a1[i-x+n-1]&&!a2[i+x]) {
				col[i] = a1[i-x+n-1] = a2[i+x] = true;
				s[i]='Q';
				tmp.push_back(s);
				dfs(x+1, n, tmp);
				s[i]='.';
				tmp.pop_back();
				col[i] = a1[i-x+n-1] = a2[i+x] = false;
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		col = vector<bool>(n+1, false);
		a1 = vector<bool>(2*n+1, false);
		a2 = vector<bool>(2*n+1, false);
		dfs(0, n, {});
		return ans;
	}
};