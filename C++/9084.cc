#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n,m;
int dp[21][10001];
int coins[21];  

int solve(int n, int m){
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    // dp[i][j] : i까지 봤을 때 , j원을 만들 수 있는 방법의 수
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(coins[i] <= j){
                dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(coins, 0, sizeof(coins));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            cin >> coins[i];
        }
        cin >> m;

        cout << solve(n,m) << endl;
    }
}
