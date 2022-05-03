#include <bits/stdc++.h>
using namespace std;

int ans;
int mp[500][500];
int dp[500][500];

int n,m;

int solve(int x, int y){
    if(x == 0 && y == 0) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    dp[x][y] = 0;
    
    for(int i = 0; i < 4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[x][y] < mp[nx][ny]){
            dp[x][y] += solve(nx, ny);
        }
    }
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(n-1, m-1) << endl;
}
