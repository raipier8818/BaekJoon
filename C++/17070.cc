#include <bits/stdc++.h>
using namespace std;

int n;
int dp[20][20][3]; // 0 : hor, 1 : ver, 2 : diag 
int f[20][20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> f[i][j];
        }
    }

    dp[1][2][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j <= 2) continue;

            if(f[i][j] == 0){
                dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][2];
                dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];
            }

            if(f[i][j] == 0 && f[i-1][j] == 0 && f[i][j-1] == 0){
                dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}   
