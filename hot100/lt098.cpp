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
    bool ans = 1;
    pair<int, int> dfs(TreeNode* x) {
        if(!ans) return make_pair(0, 0);
        if(!x) return make_pair(-1, 1e5);
        pair<int, int> pl = make_pair(x->val, x->val);
        pair<int, int> pr = make_pair(x->val, x->val);
        if(x->left) {
            pl = dfs(x->left);
            if(pl.second >= x->val) ans = 0;
        }
        if(x->right) {
            pr = dfs(x->right);
            if(pr.first <= x->val) ans = 0;
        }
        return make_pair(pl.first, pr.second);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
int main() {

}