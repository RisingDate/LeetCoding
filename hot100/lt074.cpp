//
// Created by 17732 on 26-2-2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> tmp;
		for(int i=0;i<matrix.size();i++) tmp.push_back(matrix[i][0]);
		auto p = upper_bound(tmp.begin(), tmp.end(), target);
		if(p==tmp.begin()) return false;
		else tmp = matrix[p-tmp.begin()-1];
		p = lower_bound(tmp.begin(), tmp.end(), target);
		if (p!=tmp.end()&&*p==target) return true;
		return false;
	}
};