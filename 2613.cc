#include <bits/stdc++.h>
using namespace std;

int n, m;
long long arr[300];
long long dp[301];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int left = 0;
    int right = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        left = left < arr[i] ? arr[i] : left;
        right += arr[i];

        dp[i+1] = arr[i] + dp[i];
    }

    int mid = 0;
    int group_num = 0;
    int ans = 0;
    vector<int> 

    while(left < right){
        mid = (left + right) / 2;
        
    }
}