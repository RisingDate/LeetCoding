//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	static void traverseBorder(int l, int r, int t, int b, vector<int>& res, vector<vector<int>>& matrix) {
		for (int i = l; i < r; i++)
			res.push_back(matrix[t][i]);
		for (int i = t; i < b; i++)
			res.push_back(matrix[i][r]);
		for (int i = r; i > l; i--)
			res.push_back(matrix[b][i]);
		for (int i = b; i > t; i--)
			res.push_back(matrix[i][l]);
	}
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int l = 0, t = 0, b = matrix.size()-1, r = matrix[0].size()-1;
		while (l<r && t<b) {
			traverseBorder(l,r,t,b,ans,matrix);
			++l, --r, ++t, --b;
		}
		if (l==r) for (int i=t;i<=b;i++) ans.push_back(matrix[i][l]);
		else if (t==b) for (int i=l;i<=r;i++) ans.push_back(matrix[t][i]);
		return ans;
	}
};
int main() {

}