#include <bits/stdc++.h>
using namespace std;

int n;
int dp[2000000];
int before[2000000];

void f(int val){
    before[1] = -1;
    for(int i = 2; i <= val; ++i){
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            before[i] = i/2;
        }
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            before[i] = i/3;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    f(n);
    cout << dp[n] << endl;
    while(n != -1){
        cout << n << " ";
        n = before[n];
    }
}