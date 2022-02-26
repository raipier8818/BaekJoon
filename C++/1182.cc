#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> v;

int cnt = 0;

void func(int idx, int val){
    val += v[idx];

    if(idx >= n){
        return;
    }
    if(val == s){
        cnt++;
    }

    func(idx + 1, val - v[idx]);
    func(idx + 1, val);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    func(0,0);
    cout << cnt;
}
