#include <bits/stdc++.h>
using namespace std;

int n,x;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> x;
        
        if(x == 0){
            if(pq.empty()){
                cout << 0 << "\n";
                continue;
            }

            cout << pq.top() << "\n";
            pq.pop();
            continue;
        }

        pq.push(x);
    }
}