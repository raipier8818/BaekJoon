#include <bits/stdc++.h>

using namespace std;

int arr[10][100000];
int n,m;

int dp[100000];

int find(int day,int prev){
    if(day < 0) return 0;
    if(dp[day] != 0) return dp[day];

    for(int i = 0; i < m; i++){
        if(i == prev){
            dp[day] = max(dp[day],find(day-1,i)+arr[i][day]/2);
        }
        else{
            dp[day] = max(dp[day],find(day-1,i)+arr[i][day]);
        }
    }

    return dp[day];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < m; i++){
        result = max(result,find(n-1,i));
    }

    cout << result << endl;

}