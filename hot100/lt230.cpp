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
struct Tree {
    int val;
    int size;
    Tree* left;
    Tree* right;
    Tree(): val(0), size(0), left(nullptr), right(nullptr) {}
    Tree(int x): val(x), size(1), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int dfs(TreeNode* x, Tree* tree) {
        if(!x->left&&!x->right) {
            tree->size = 1;
            return 1;
        }
        int lSize = 0, rSize = 0;
        if(x->left) {
            tree->left = new Tree(x->left->val);
            lSize = dfs(x->left, tree->left);
        }
        if(x->right) {
            tree->right = new Tree(x->right->val);
            rSize = dfs(x->right, tree->right);
        }
        tree->size = lSize + 1;
        return lSize + rSize + 1;
    }
    int kthSmallest(TreeNode* root, int k) {
        Tree *tree = new Tree(root->val);
        dfs(root, tree);
        int cnt = 0;
        Tree* x = tree;
        while(cnt<k) {
            if(x && cnt+x->size == k) return x->val;
            else if(x && cnt+x->size<k) cnt+=x->size, x=x->right;
            else if(x) x=x->left;
        }
        return x->val;
    }
};

int main() {
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p->left->right = new TreeNode(2);
    Solution s;
    cout<<s.kthSmallest(p, 1);
}