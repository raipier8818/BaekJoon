#include <bits/stdc++.h>

using namespace std;

int N,K;
int T = 1000000007;

int pow_dp[10000000];

int pow(int a, int b){
    if(b == 0) return pow_dp[0] = 1;
    if(b == 1) return pow_dp[1] = a;
    if(pow_dp[b] != 0) return pow_dp[b];
    
    if(b % 2 == 0){
        return pow_dp[b] = (pow(a,b/2) % T * pow(a,b/2) % T) % T;
    }
    else{
        return pow_dp[b] = (pow(a,b/2) * pow(a,b/2) * a % T) % T;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    // C(N, K) = C(N-1, K-1) + C(N-1, K)
    int factorial[N+1];
    factorial[0] = 1;
    for(int i = 1; i <= N; i++){
        factorial[i] = (factorial[i-1] * i) % T;
    }

    /*
     * ans = (Fac(N) / (Fac(K) * Fac(N-K))) % T
     *     = (Fac(N) * (Fac(K) * Fac(N-K))^-1) % T
     *     = (Fac(N) * (Fac(K) * Fac(N-K))^-1 % T) % T
     *     = (Fac(N) * (Fac(K) * Fac(N-K)) ^ (T - 2) % T) % T // Fermat's little theorem
     */

    int ans = factorial[N] * pow(factorial[K] * factorial[N-K], T-2) % T;

    cout << ans << endl;
}