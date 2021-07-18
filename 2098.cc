#include <bits/stdc++.h>
using namespace std;

int n;
int w[17][17];
int dp[200000][20];


int find(int bit,int idx){
    if(bit == (1 << n) - 1){
        if(w[idx][0] == 0) return 987654321;
        return w[idx][0];
    }

    if(dp[bit][idx] != 0) return dp[bit][idx];
    dp[bit][idx] = 987654321;

    for(int i = 0; i <= n; i++){
        if((bit & (1 << i)) == 0 && w[idx][i] != 0){
            dp[bit][idx] = min(find(bit | (1 << i), i) + w[idx][i], dp[bit][idx]);
        }
    }
    //cout << bit << " " << idx << " " << dp[bit][idx] << "\n";

    return dp[bit][idx];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
            // dp[i][j] = INT_MAX;

        }
    }

    cout << find(1,0);
}