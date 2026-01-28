//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	static void traverseBorder(int l, int r, int t, int b, vector<vector<int>>& matrix) {
		int x=l;
		for (int i = t; i < b; i++)
			swap(matrix[t][x++], matrix[i][r]);
		x=l;
		for (int i = r; i > l; i--)
			swap(matrix[t][x++], matrix[b][i]);
		x=l;
		for (int i = b; i > t; i--)
			swap(matrix[t][x++], matrix[i][l]);
	}
	void rotate(vector<vector<int>>& matrix) {
		int l = 0, t = 0, b = matrix.size()-1, r = matrix[0].size()-1;
		while (l<r && t<b) {
			traverseBorder(l,r,t,b,matrix);
			++l, --r, ++t, --b;
		}
	}
};
int main() {
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	Solution s;
	s.rotate(matrix);
}