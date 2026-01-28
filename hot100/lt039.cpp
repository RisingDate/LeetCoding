//
// Created by Vier on 26-1-29.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int x, int sum, int target, vector<int>& values, vector<int>& candidates) {
        if(sum==target) {ans.push_back(values);return ;}
        if (x>=candidates.size()) return;
        for(int i=0; sum+candidates[x]*i<=target; i++) {
            for(int j=0;j<i;j++) values.push_back(candidates[x]);
            dfs(x+1, sum+candidates[x]*i, target, values, candidates);
            for(int j=0;j<i;j++) values.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> values;
        dfs(0, 0, target, values, candidates);
        return ans;
    }
};

int main() {
    vector<int> a = {2,3,6,7};
    Solution s;
    s.combinationSum(a, 7);
}
