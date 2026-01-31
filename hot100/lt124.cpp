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
    int ans = -INT_MAX;
    int dfs(TreeNode* x) {
        if(!x) return 0;
        int l = dfs(x->left);
        int r = dfs(x->right);
        ans = max(ans, l + r + x->val);
        return max(max(0, max(l, r)) + x->val, 0);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
int main() {
    // TreeNode* rt = new TreeNode(-10);
    // rt->left = new TreeNode(9);
    // rt->right = new TreeNode(20);
    // rt->right->left = new TreeNode(15);
    // rt->right->right = new TreeNode(7);
    TreeNode* rt = new TreeNode(-2);
    Solution s;
    cout<<s.maxPathSum(rt);
}