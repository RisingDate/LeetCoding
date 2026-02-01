//
// Created by Vier on 26-2-1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<char>> dig = {{}, {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> ans;
    void dfs(int x, string tmp, string digits) {
        if(x==digits.length()) {
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<dig[digits[x]-'0'].size();i++) {
            dfs(x+1, tmp+dig[digits[x]-'0'][i], digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        dfs(0, "", digits);
        return ans;
    }
};
int main() {
    Solution s;

}