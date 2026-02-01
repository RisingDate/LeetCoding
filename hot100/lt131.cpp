//
// Created by Vier on 26-2-1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> ans;
    bool a[20][20];
    bool check(int l, int r, string s) {
        while(l<=r)
            if(s[l++]!=s[r--]) return 0;
        return 1;
    }
    void dfs(int preDivide, int tmpDevide, string s, vector<string> tmp) {
        if(preDivide==tmpDevide&&preDivide==s.length()) {
            ans.push_back(tmp);
            return ;
        }
        if(tmpDevide>=s.length()) return ;
        if(a[preDivide][tmpDevide]) {
            tmp.push_back(s.substr(preDivide, tmpDevide-preDivide+1));
            dfs(tmpDevide+1, tmpDevide+1, s, tmp);
            tmp.pop_back();
        }
        dfs(preDivide, tmpDevide+1, s, tmp);
    }
    vector<vector<string>> partition(string s) {
        for(int i=0; i<s.length();i++) for(int j=i;j<s.length();j++)
            a[i][j]=check(i,j,s);
        dfs(0,0,s,{});
        return ans;
    }
};
int main() {
    Solution s;
    string str = "aab";
    s.partition(str);
}