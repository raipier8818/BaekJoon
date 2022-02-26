#include <bits/stdc++.h>
using namespace std;

int n, m;
bool arr[1001][1001];
bool v[1001];

stack<int> dfs;

bool check;
void find(int start){
    if(v[start] == true) return;

    check = true;
    v[start] = true;
    for(int i = 1; i <= n; i++){
        if(arr[start][i] == 1 && v[i] == false){
            find(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        check = false;
        find(i);
        if(check) count++;
        /*
        cout << "[ ";
        for(int j = 1; j <= n; j++){
            cout << v[j] << " ";
        }
        cout << " ]\n";
        */
    }

    cout << count;
}