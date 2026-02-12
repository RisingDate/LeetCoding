//
// Created by 17732 on 26-2-12.
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
	TreeNode* dfs(TreeNode* x) {
		if (!x->left && !x->right) return x;
		TreeNode *l = nullptr, *r = nullptr;
		if (x->left) l = dfs(x->left);
		if (x->right) r = dfs(x->right);

		TreeNode *newHead = nullptr;
		if (l) {
			newHead = l;
			while (l->right) l = l->right;
			l->right = r;
		}
		else newHead=r;
		x->left = nullptr;
		x->right = newHead;
		return x;
	}
	void flatten(TreeNode *root) {
		if (!root) return;
		dfs(root);
	}
};
int main() {
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(6);
	s.flatten(root);
	while (root) cout<<root->val<<endl, root = root->right;
}