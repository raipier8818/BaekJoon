#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int,int>> pos;

void find(){
    for(int i = 0; i < pos.size(); i++){
        int r = pos[i].first;
        int c = pos[i].second;

        int visit[9] = {0,};
        //check row
        for(int row = 0; row < 9; row++){
            if(pos[i].first == row) continue;
            visit[board[row][c]] = 1;
        }
        //check col
        for(int col = 0; col < 9; col++){
            if(pos[i].second == col) continue;
            visit[board[r][col]] = 1;
        }

        //check box



    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) pos.push_back(make_pair(i,j));
        }
    }
}