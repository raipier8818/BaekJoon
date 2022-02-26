#include <bits/stdc++.h>
using namespace std;

int n;
int a,b;
int arr[101][101];
int v[101];
int answer = INT_MAX;

void find(int pos, int count, int des){
    if(v[pos] == 1) return;
    if(pos == des){
        answer = count < answer ? count : answer;
        //cout << answer << " check\n";
        return;
    }
    v[pos] = 1;
    //cout << "pos " << pos << " " << count << "\n";
    for(int i = 1; i <= n; i++){
        if(arr[pos][i]) find(i, count + 1, des);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> a >> b;
    int m; cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    find(a,0,b);
    cout << (answer == INT_MAX ? -1 : answer);
}