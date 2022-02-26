#include <bits/stdc++.h>
using namespace std;

int t;
int n,m;

vector<pair<int,int>> v;
vector<int> check;

bool comp_first(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

bool comp_second(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}


bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        v.clear();
        check.clear();
        check.resize(n + 1);

        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }

        sort(v.begin(), v.end(), comp);

        int answer = 0;
        for(int i = 0; i < m; i++){
            for(int j = v[i].first; j <= v[i].second; j++){
                if(check[j] == 0){
                    check[j] = 1;
                    answer++;
                    break;
                }
            }
        }

        cout << answer << "\n";   
    }
}