#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10000];
int dp[1000];
int dp_[1000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                dp[j] = max(dp[j], dp[i] + 1);
            }else{
                dp[j] = dp[i];
            }
        }
    }

    int maxidx = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] > dp[maxidx]) maxidx = i;
        dp_[i] = 9999999;
    }

    

    for(int i = maxidx; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                dp_[j] = min(dp_[j], dp_[i] + 1);
            }else{
                dp_[j] = dp_[i];
            }
        }
    }


    cout << dp[n-1];
    cout << dp_[n-1];
}