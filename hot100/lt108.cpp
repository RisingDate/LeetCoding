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
    TreeNode* dfs(int l, int r, vector<int>& nums) {
        if(l>r) return nullptr;
        if(l==r) return new TreeNode(nums[l]);
        int mid = l+r>>1;
        TreeNode* tmp = new TreeNode(nums[mid]);
        tmp->left = dfs(l, mid-1, nums);
        tmp->right = dfs(mid+1, r, nums);
        return tmp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size()-1, nums);
    }
};
int main() {
    vector<int> num = {1,2};
    Solution s;
    s.sortedArrayToBST(num);

}