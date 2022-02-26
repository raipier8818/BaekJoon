#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> pq;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pq.push(v[i]);
    }

    int ans = 0;
    while(!pq.empty()){
        int first = pq.top();
        pq.pop();
        if(pq.empty()) break;

        int second = pq.top();
        pq.pop();

        ans += (first + second);
        pq.push(first + second);
        // cout << ans << endl;
    }

    cout << ans;

}