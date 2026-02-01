//
// Created by Vier on 26-2-1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool inq = 0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(int x, int y, vector<vector<char>>& board, string word, int pos) {
        if(inq||pos==word.length()) {
            inq=1;
            return ;
        }
        for(int i=0; i<4;i++) {
            int xx=x+dx[i], yy=y+dy[i];
            if(xx<0||xx>=board.size()||yy<0||yy>=board[0].size()||board[xx][yy]!=word[pos])
                continue;
            char ch=board[xx][yy];
            board[xx][yy] = ' ';
            dfs(xx, yy, board, word, pos+1);
            board[xx][yy] = ch;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]==word[0]) {
                    char ch=board[i][j];
                    board[i][j] = ' ';
                    dfs(i,j,board,word,1);
                    if(inq) return true;
                    board[i][j] = ch;
                }
        return false;
    }
};
int main() {
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    s.exist(board, "SEE");

}