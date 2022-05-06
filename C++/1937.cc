#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int arr[500][500];
int dp[500][500];

int solve(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};

    dp[x][y] = 1;
    int temp = 0;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < n && arr[x][y] < arr[nx][ny]){
            temp = max({solve(nx, ny), temp});
        }a
    }

    return dp[x][y] += temp;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max({solve(i,j), ans});
            // cout << dp[i][j] <<  " ";
        }
        // cout << endl;
    }

    cout << ans << endl;
}
