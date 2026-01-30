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
    int dfs(TreeNode* x) {
        if(!x) return -1;
        int l = dfs(x->left)+1;
        int r = dfs(x->right)+1;
        ans = max(ans, l+r);
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};