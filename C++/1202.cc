#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;

vector<pair<int,int>> j;
vector<int> b;

bool compair(pair<int,int> left, pair<int,int> right){
    return left.first < right.first;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    while(n--){
        int m,v;
        cin >> m >> v;
        j.push_back(make_pair(m,v));
    }
    while(k--){
        int c;
        cin >> c;
        b.push_back(c);
    }
    sort(j.begin(), j.end(), compair);
    sort(b.begin(), b.end());


    priority_queue<int> pq;
    int idx = 0;
    long long ans = 0;
    for(int i = 0; i < b.size(); i++){
        while(idx < j.size() && j[idx].first <= b[i]){
            pq.push(j[idx++].second);
        }

        if (!pq.empty())
        {   
            ans += pq.top();
            pq.pop();
        }
        
    }

    cout << ans;
}