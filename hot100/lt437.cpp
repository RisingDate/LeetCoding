//
// Created by Vier on 26-1-31.
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
#define ll long long
    int ans=0;
    void check(TreeNode* x, ll sum, int targetSum) {
        if(sum == targetSum) ans++;
        if(!x) return ;
        if(x->left) check(x->left, sum+x->left->val, targetSum);
        if(x->right) check(x->right, sum+x->right->val, targetSum);
    }
    void dfs(TreeNode* x, int targetSum) {
        if(!x) return ;
        check(x, x->val, targetSum);
        dfs(x->left, targetSum);
        dfs(x->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};
int main() {
    TreeNode* rt = new TreeNode(10);
    rt->left = new TreeNode(5);
    rt->right = new TreeNode(-3);
    rt->left->left = new TreeNode(3);
    rt->left->right = new TreeNode(2);
    rt->right->right = new TreeNode(11);
    rt->left->left->left = new TreeNode(3);
    rt->left->left->right = new TreeNode(-2);
    rt->left->right->right = new TreeNode(1);
    Solution s;
    cout<<s.pathSum(rt, 8);

}