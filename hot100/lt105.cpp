//
// Created by 17732 on 26-1-31.
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
	TreeNode* dfs(int l1, int r1, int l2, int r2, vector<int>& preorder, vector<int>& inorder) {
		if (l1 > r1) return nullptr;
		if (l1 == r1) return new TreeNode(preorder[r1]);
		int val = preorder[l1], mid;
		for (int i=l2; i<=r2; i++) if (inorder[i]==val) {
			mid=i; break;
		}
		TreeNode* lt = dfs(l1+1, l1+mid-l2, l2, mid-1, preorder, inorder);
		TreeNode* rt = dfs(l1+mid-l2+1, r1, mid+1, r2, preorder, inorder);
		return new TreeNode(val, lt, rt);
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return dfs(0, preorder.size()-1, 0, preorder.size()-1,  preorder, inorder);
	}
};
int main() {
	Solution s;
	vector<int> preorder = {1,2};
	vector<int> inorder = {2,1};
	TreeNode* root = s.buildTree(preorder, inorder);
}