#include <bits/stdc++.h>
using namespace std;

int N,L,R;
long long dp[101][101][101];

long long solve(int n, int l, int r){
    if(n == 0 || l < 0 || r < 0) return 0;
    if(l == 0 || r == 0) return 1;
    if(dp[n][l][r] != -1) return dp[n][l][r];

    dp[n][l][r] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = l; j <= n-r; j++){
            dp[n][l][r] += solve(n-i, )
        }
    }

    return dp[n][l][r];
}

/*

f(5,3,2) = (f(3,2,1) + f(3,2,2)) * f(1,1,1)

f(8,3,2) = (f(6,2,1) + f(6,2,2) + f(6,2,3) + f(6,2,4) + f(6,2,5)) * f(1,1,1)
         + (f(5,2,1) + f(5,2,2) + f(5,2,3) + f(5,2,4)) * (f(2,1,1) + f(2,2,1))

*/

int main(){
    cin >> N >> L >> R;
    memset(dp, -1, sizeof(dp));
}