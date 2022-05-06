#include <bits/stdc++.h>
using namespace std;

int n,k;
long long dp[201][201];

int solve(int n, int k){
    if(dp[n][k] != -1) return dp[n][k];

    dp[n][k] = 0;

    for(int i = 0; i <= n; i++){
        dp[n][k] += solve(i, k-1) * solve(n-i, 1);
    }
    dp[n][k] %= 1000000000;

    return dp[n][k];
}

int main(){
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(int i = 1; i <= k; i++){
        dp[0][i] = 1;
    }

    cout << solve(n,k) << endl;
    
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}