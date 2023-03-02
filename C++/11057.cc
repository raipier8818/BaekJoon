#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i <= 9; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = j; k >= 0; k--){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += dp[n][i];
    }

    cout << ans % 10007<< endl;
}
