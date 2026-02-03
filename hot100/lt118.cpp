//
// Created by Vier on 26-2-4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp = {1};
        ans.push_back(tmp);
        for(int i=1; i<numRows; i++) {
            vector<int> pre = ans[i-1];
            tmp = {1};
            for(int j=1; j<=i; j++) {
                int x;
                if(j>=0&&j<pre.size()) x=pre[j];
                else x=0;
                tmp.push_back(x+pre[j-1]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};