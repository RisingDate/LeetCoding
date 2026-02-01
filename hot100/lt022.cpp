//
// Created by Vier on 26-2-1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void dfs(int l, int r, int n, string tmp) {
        if(l==n && r==n) {
            ans.push_back(tmp);
            return;
        }
        if(l<n) dfs(l+1, r, n, tmp+'(');
        if(r<l) dfs(l, r+1, n, tmp+')');
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n,"");
        return ans;
    }
};
int main() {
    Solution s;

}