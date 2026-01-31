//
// Created by Vier on 26-1-31.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int totOriges = 0;
        for (int i=0; i<n; i++) for(int j=0; j<m; j++) {
            if(grid[i][j]!=0) ++totOriges;
            if(grid[i][j]==2) q.push_back({i,j});
        }
        int ans=0, cnt=0;
        for(ans = 0; q.size()!=totOriges; ans++) {
            if(q.size()==cnt && cnt) return -1;
            cnt = q.size();
            for(int i=0;i<cnt;i++) {
                for(int j=0;j<4;j++) {
                    int xx=q[i].first+dx[j], yy=q[i].second+dy[j];
                    if(xx<0 || xx>=n || yy<0 || yy>=m || grid[xx][yy]!=1) continue;
                    q.push_back({xx,yy});
                    grid[xx][yy] = 2;
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> p = {{0}};
    Solution s;
    cout<<s.orangesRotting(p);
}