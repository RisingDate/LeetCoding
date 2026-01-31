//
// Created by Vier on 26-1-31.
//
#include<bits/stdc++.h>
#include<bit>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int bit_width(int x) {
        int res = 0;
        while(x) x>>=1, ++res;
        return res;
    }
    vector<pair<int, int>> res;
    void dfs(TreeNode* x, int id) {
        if(!x) return ;
        int idx = bit_width(id)-1;
        if(res.size()<=idx) res.push_back(make_pair(x->val, id));
        else if(res[idx].second < id) res[idx] = make_pair(x->val, id);
        dfs(x->left, id<<1);
        dfs(x->right, id<<1|1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        vector<int> ans;
        for(auto &p: res) ans.push_back(p.first);
        return ans;
    }
};