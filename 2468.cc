#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int visit[100][100];
int n;
int M,m;




int find(){
    for(int i = m-1; i <= M; i++){

    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    M = 0;
    m = 987654321;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            M = max(M,arr[i][j]);
            m = min(m,arr[i][j]);
        }
    }
}