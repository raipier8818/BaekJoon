#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> dp;
int n;

int arr[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        //cout << arr[i] << endl;
        dp[i] = 0;   
    }

    for(int i = 0; i < n; i++){
        if(i == 0) dp[i] = arr[i];
        else dp[i] = max(dp[i-1] + arr[i], arr[i]);
        //cout << dp[i] << endl;
    }

    cout << *max_element(dp.begin(),dp.end()) << endl;


}