//
// Created by Vier on 26-4-2.
//

// Definition for a QuadTree node.
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node *dfs(int l, int r, int t, int b, vector<vector<int> > &grid) {
        Node *p = new Node();
        bool inq = 0;
        for (int i = t; i <= b; i++)
            for (int j = l; j <= r; j++)
                if (grid[i][j] ^ grid[t][l]) {
                    inq = 1;
                    break;
                }
        if (!inq) {
            p->val = grid[t][l];
            p->isLeaf = 1;
        } else {
            p->isLeaf = 0;
            p->val = 0;
            int lmid=l+r>>1;
            int tmid=t+b>>1;
            p->topLeft = dfs(l, lmid, t, tmid, grid);
            p->topRight = dfs(lmid+1, r, t, tmid, grid);
            p->bottomLeft = dfs(l, lmid, tmid+1, b, grid);
            p->bottomRight = dfs(lmid+1, r, tmid+1, b, grid);
        }
        return p;
    }

    Node *construct(vector<vector<int> > &grid) {
        return dfs(0, grid[0].size() - 1, 0, grid.size() - 1, grid);
    }
};
