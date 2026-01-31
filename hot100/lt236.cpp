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
    pair<TreeNode*, int> ans = make_pair(nullptr, 0);
    int dfs(TreeNode* x, int dep, int p, int q) {
        if(!x) return 0;
        int tmp = 0;
        if(x->val == p || x->val == q) tmp = 1;
        int l = dfs(x->left, dep+1, p, q);
        int r = dfs(x->right, dep+1, p, q);
        if(l+r+tmp == 2 && ans.second<=dep) ans = make_pair(x, dep);
        return l+r + tmp;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, 0, p->val, q->val);
        return ans.first;
    }
};
int main() {
    TreeNode* rt = new TreeNode(3);
    rt->left = new TreeNode(5);
    rt->right = new TreeNode(1);
    rt->left->left = new TreeNode(6);
    rt->left->right = new TreeNode(2);
    rt->right->left = new TreeNode(0);
    rt->right->right = new TreeNode(8);
    rt->left->right->left = new TreeNode(7);
    rt->left->right->right = new TreeNode(4);
    Solution s;
    TreeNode* p = rt->left;
    TreeNode* q = rt->right;
    TreeNode* anc = s.lowestCommonAncestor(rt, p, q);
    cout<<anc->val;
}