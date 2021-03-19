#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10][101];

int find(int index,int length){
    if(index < 0 || index > 9) return 0;
    
    
    if(length == 0) return 0;
    if(dp[index][length] != 0) return dp[index][length]%1000000000;

    
    return dp[index][length] = (find(index-1,length-1)%1000000000 + find(index+1,length-1)%1000000000)%1000000000;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i <= 9; i++){
        if(i == 0) dp[i][1] = 0;
        else
        {
            dp[i][1] = 1;
        }
        
    }


    int p = 0;
    for(int i = 0; i <= 9; i++){
        p += find(i,n)%1000000000;
        p %= 1000000000;
    }

    cout << p << endl;
    
}