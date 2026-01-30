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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> tmp;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1, newCnt = 0;
        while(!q.empty()) {
            TreeNode* x = q.front();
            q.pop();
            tmp.push_back(x->val);
            --cnt;
            if(x->left) q.push(x->left),++newCnt;
            if(x->right) q.push(x->right),++newCnt;
            if(!cnt) ans.push_back(tmp), tmp.clear(), cnt=newCnt, newCnt=0;
        }
        return ans;
    }
};