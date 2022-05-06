#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[31];

int main(){
    cin >> n;

    dp[2] = 3;
    dp[4] = 9 + 2;

    for(int i = 6; i <= n; i+=2){
        for(int j = 2; j < i; j+=2){
            dp[i] += dp[j] * dp[i-j];
        }
    }

    cout << dp[n] << endl;
}