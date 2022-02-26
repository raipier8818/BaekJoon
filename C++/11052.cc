/*
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int find(int card){
    if(card == 0) return 0;
    if (dp[card] != 0) return dp[card];

    int result = 0;
    for(int i = 1; i <= card; i++){
        result = max(result,find(card-i)+arr[i]);
    }

    return dp[card] = result;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    dp[0] = 0;

    cout << find(n) << endl;

}
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int find(int card){
    if(card == 0) return 0;
    if (dp[card] != 0) return dp[card];

    int result = 0;
    for(int i = 1; i <= card; i++){
        result = max(result,find(card-i)+arr[i]);
    }

    return dp[card] = result;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];

    for(int i = 1; i <= n; i++){
        int result = 0;
        
        for(int j = 1; j <= i; j++){
            result = max(result, dp[i-j]+arr[j]);
        }
        dp[i] = result;
    }

    cout << dp[n] << endl;

}