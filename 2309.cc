#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int visit[9];
vector <int> arr;


void dfs(int prev,int count,int sum){
    if(count == 7 && sum == 100){
        for(int i = 0; i < 9; i++){
            if(visit[i] != 0) cout << arr[i] << "\n";
        }
        exit(0);
    }

    for(int i = prev; i < 9; i++){
        if(visit[i] == 0)
        {
            visit[i] = 1;
            dfs(i,count+1,sum+arr[i]);
            visit[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    arr.resize(9);
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());


    dfs(0,0,0);
}