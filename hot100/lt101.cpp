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
    bool ans=1;
    void dfs(TreeNode* x, TreeNode* y) {
        if(!ans || !x&&!y) return ;
        if(!x&&y || x&&!y || x->val!=y->val) {ans=0; return ;}
        if(!x) return ;

        dfs(x->left, y->right);
        dfs(x->right, y->left);
    }
    bool isSymmetric(TreeNode* root) {
        dfs(root->left, root->right);
        return ans;
    }
};