//
// Created by 17732 on 26-1-28.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		unordered_set<int> c,r;
		for(int i=0;i<matrix.size();i++)
			for(int j=0;j<matrix[0].size();j++)
				if(matrix[i][j] == 0)
					r.insert(i), c.insert(j);
		for(int i=0;i<matrix.size();i++)
			for(int j=0;j<matrix[0].size();j++)
				if (r.find(i)!=r.end() || c.find(j)!=c.end())
					matrix[i][j] = 0;
	}
};
int main() {

}