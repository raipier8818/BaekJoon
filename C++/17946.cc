#include <bits/stdc++.h>

using namespace std;
int n;
long long dp[1001];

long long find(int num){
    if (num == 0) return 1;
    if(dp[num] != 0) return dp[num];

    return dp[num] = find(num-1)*2 - 1;
}

int main(){
    cin >> n;
    dp[1] = 2;
    dp[2] = 4;
    int num;
    for(int j = 0; j < n; j++){
        //cout << j << endl;
        cin >> num;

        cout << 1 << endl;
    }

    
    
}