#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int dp[1001];
/*
int find(int index){
    if (index == 0) return 1;
    if(dp[index] != 0) return dp[index];

    int result = 1;


    for(int i = 1; i <= index; i++){
        if(arr[index] > arr[index-i]){
            result = max(find(index-i)+1,result);
        }
    }

    return dp[index] = result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    find(n-1);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) find(i);

    cout << *max_element(dp,dp+n) << endl;

}*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i <= n; i++){
        if(i == 0){
            dp[i] = 1;
            continue;
        }
        int result = 1;
        for(int j = 0; j <= i; j++){
            if(arr[i] > arr[i-j]){
                result = max(dp[i-j]+1,result);
            }
        }
        dp[i] = result;
    }


    //for(int i = 0; i < n; i++) cout << dp[i] << " m" << endl;
    
    cout << *max_element(dp,dp+n) << endl;

}