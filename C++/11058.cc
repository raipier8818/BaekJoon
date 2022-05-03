#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[101];
int ans;

long long solve(int x){
    if(x <= 0) return 0;

    if(dp[x] != -1) return dp[x];
    dp[x] = solve(x-1) + 1;

    for(int i = 3; i < x; i++){
        dp[x] = max({dp[x], solve(x-i) * (i-1)});
    }
    // cout << " :: " << x << " :: " << dp[x] << endl;
    return dp[x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    memset(dp, -1, sizeof(dp));

    
    cout << solve(n) << endl;
}
