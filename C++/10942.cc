#include <bits/stdc++.h>

using namespace std;

int n,m,s,e;

int arr[2001];
bool dp[2001][2001];


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        dp[i][i] = true;
    }

    for(int i = 0; i < n-1; i++){
        if(arr[i] == arr[i+1]){
            dp[i][i+1] = true;
        } 
    }

    for(int i = 2; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(arr[j] == arr[j+i] && dp[j+1][j+i-1]){
                dp[j][j+i] = true;
                dp[j+i][j] = true;
            }
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s-1][e-1]);
    }

}