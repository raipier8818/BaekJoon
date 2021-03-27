#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[300];
int dp[301];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i == 0){
            dp[i+1] = arr[i];
            continue;
        }

        dp[i+1] = dp[i] + arr[i];
    }   

    int start = 0;
    int end = n - 1;

    while(start <= end){
        int mid = (start + end) / 2;

        for(int i = 0; i < mid; i++){
            
        }
    }


}