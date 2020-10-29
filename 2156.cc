#include <bits/stdc++.h>
int n;
int dp[10001];
int arr[10001];

using namespace std;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 1; i <= n; i++){
        /*
        if(i == 0) dp[i] = arr[i];
        else if(i == 1) dp[i] = dp[i-1] + arr[i];
        else if(i == 2) dp[i] = max(arr[i-1], dp[i-2]) + arr[i];
        else dp[i] = max(arr[i-1] + dp[i-3], dp[i-2]) + arr[i];
        */

        if(i == 0) dp[i] = 0;
        else if(i == 1) dp[i] = arr[i];
        else if(i == 2) dp[i] = arr[i] + arr[i-1];
        else dp[i] = max({arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2], dp[i-1]});

        //printf("-- %d --\n", dp[i]);
    }

    printf("%d\n", dp[n]);
}