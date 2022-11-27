#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
vector<int> files;
int dp[501][501];
int inf = 999999999;

void printDP(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout<<endl;
    }
}


int solve(int start, int end){
    // cout << start << "-" << end << " : " << dp[start][end] << endl;
    if(start == end) return 0;
    if(start - end == -1) return dp[start][end] = files[start] + files[end];
    if(dp[start][end] != 0x3f3f3f3f) return dp[start][end];  
    dp[start][end] = inf;
    for(int i = start; i < end; i++){
        dp[start][end] = min(dp[start][end], solve(start, i) + solve(i + 1, end));
    }

    dp[start][end] += dp[end][end] - dp[start-1][start-1];
    // cout << start << "-" << end << " : " << dp[start][end] << endl;
    return dp[start][end];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        files.clear();
        files.resize(n+1);
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1; i <= n; i++){
            cin >> files[i];
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i][i] = dp[i-1][i-1] + files[i];
        }
        cout << solve(1, n) << endl;
        // printDP(n+1);
    }
}
