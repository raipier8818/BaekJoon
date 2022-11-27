#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int bites[101];
int costs[101];
int dp[101][10101];
int sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> bites[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> costs[i];
        sum += costs[i];
    }

    // dp[i][j] : i까지 봤을 때, j의 비용으로 만들 수 있는 메모리 최댓값.
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(j >= costs[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-costs[i]] + bites[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    
    for(int i = 0; i < sum; i++){
        if(dp[n][i] >= m){
            cout << i << endl;
            return 0;
        }
    }
}
