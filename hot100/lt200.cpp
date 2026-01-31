//
// Created by Vier on 26-1-31.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y] != '1') return;
        grid[x][y] = '0';
        dfs(x+1, y, grid);
        dfs(x-1, y, grid);
        dfs(x, y+1, grid);
        dfs(x, y-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            if(grid[i][j] == '1') ++ans, dfs(i,j,grid);
        return ans;
    }
};