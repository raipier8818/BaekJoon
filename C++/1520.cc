#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[500][500];

int c = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void count(){
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));

    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();

        if(cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m) continue;
        if(cur.first == n - 1 && cur.second == m - 1){
            c += 1;
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(board[nx][ny] < board[cur.first][cur.second]){
                q.push(make_pair(nx,ny));
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    count();
    cout << c << endl;

}