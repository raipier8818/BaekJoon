#include <bits/stdc++.h>
using namespace std;

int n, e;
long long m[801][801];
long long answer = __LONG_LONG_MAX__;


void find(int pos, long long weight){
    if(pos == n){
        
        return;
    }


    int min_weight = 1001;
    for(int i = 1; i <= n; i++){
        if(i == pos) continue;
        
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    memset(m,2000,sizeof(m));

    for(int i = 0; i < e; i++){
        int a,b,c;
        cin >> a >> b >> c;

        m[a][b] = c;
        m[b][c] = c;
    }


}