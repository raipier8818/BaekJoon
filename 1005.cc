#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
int arr[1001][1001];
int buildings[1001];
int dp[1001];

int x, y, w;

int find(int idx){
    if(dp[idx] != -1) return dp[idx];

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(arr[idx][i]) ans = find(i) > ans ? find(i) : ans;
    }

    return dp[idx] = ans + buildings[idx];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        memset(arr,0,sizeof(arr));
        memset(buildings,0,sizeof(buildings));
        memset(dp,-1,sizeof(dp));
        
        
        
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> buildings[i]; 
        }

        for(int i = 0; i < k; i++){
            cin >> x >> y;
            arr[y][x] = 1;
        }

        cin >> w;

        cout << find(w) << "\n";
    }
}