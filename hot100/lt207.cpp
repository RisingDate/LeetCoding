//
// Created by Vier on 26-2-1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> preHead(numCourses, 0);
        vector<vector<int>> e(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            e[prerequisites[i][0]].push_back(prerequisites[i][1]);
            preHead[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) if(!preHead[i]) q.push(i);
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            for(int i=0;i<e[x].size();i++) {
                preHead[e[x][i]]--;
                if(!preHead[e[x][i]]) q.push(e[x][i]);
            }
        }
        bool ans=1;
        for(int i=0;i<numCourses;i++) if(preHead[i]) ans=0;
        return ans;
    }
};