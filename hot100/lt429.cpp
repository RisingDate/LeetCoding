//
// Created by Vier on 26-4-2.
//
#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        int layerNum=1, newLayerNum=0;
        vector<vector<int>> ans;
        vector<int> layerAns;
        if(root) q.push(root);
        while(!q.empty()) {
            Node* x=q.front();
            layerAns.push_back(x->val), q.pop(), layerNum--;
            for(auto it=x->children.begin(); it!=x->children.end(); it++) {
                q.push(*it);
                newLayerNum++;
            }
            if(!layerNum) {
                layerNum=newLayerNum;
                newLayerNum=0;
                ans.push_back(layerAns);
                layerAns.clear();
            }
        }
        return ans;
    }
};