#include <bits/stdc++.h>
using namespace std;

bool isValidPos(vector<vector<int>> board, int row, int col) {
    int n = board.size();
    for(int j=0; j<n; ++j) {
        if(j!=col && board[row][j]==1) {
            return false;
        }
    }
}
void backtrack(vector<vector<int>>&board, int col) {
    int n = board.size();
    int row;
    for(int i=0; i<n; ++i) {
        if(isValidPos(board,i,col)) {
            board[i][col] = 1;
            row = i;
            backtrack(board, col+1);
        }
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> board(n,vector<int>(n,0));

    return 0;
}