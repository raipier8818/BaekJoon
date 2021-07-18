#include <bits/stdc++.h>
using namespace std;

int n,m;
char board[11][11];

typedef struct _point{
    int row;
    int col;
    int count;
}point;

bool equal(point l, point r){
    return (l.row == r.row && l.col == r.col);
}

point red;
point blue;
point hole;

int c = INT_MAX;



void find(point r, point b, int count){
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];

            if(board[i][j] == 'R') red = {i,j,0};
            if(board[i][j] == 'B') blue = {i,j,0};
            if(board[i][j] == 'O') hole = {i,j,0};
        }
    }

    find(red, blue, 0);
    cout << c << endl;
}