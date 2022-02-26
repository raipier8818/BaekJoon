#include <bits/stdc++.h>

using namespace std;

int n,m;
int board[500][500];
int ans = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


void find(int row, int col, int val, int count){
    if(count == 4){
        ans = max(ans,val);
        return;
    }

    if(row < 0 || row >= n || col < 0 || col >= m){
        return;
    }

    for(int i = 0; i < 4; i++){
        int nextX = row + dx[i];
        int nextY = col + dy[i];

        find(nextX,nextY, val + board[row][col], count+1);
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            find(i,j,0,0);
        }
    }
    cout << ans << endl;
}