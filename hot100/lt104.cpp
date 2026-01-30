//
// Created by Vier on 26-1-30.
//
#include<bits/stdc++.h>
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
    int ans=0;
    void dfs(TreeNode* x, int dep) {
        if(!x) return ;
        ans=max(ans,dep);
        dfs(x->left, dep+1);
        dfs(x->right, dep+1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};