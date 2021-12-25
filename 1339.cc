#include <bits/stdc++.h>
using namespace std;

int N;

map<char, int> m;
string str[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str[i];
        int dec = 1;
        for(int j = str[i].size() - 1; j >= 0; j--){
            m[str[i][j]] += dec;
            dec *= 10;
        }
    }

    vector<pair<char, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b){
        return a.second > b.second;
    });

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    int ans = 0;

    for(int i = 9, j = 0; j < v.size(); i--, j++){
        ans += v[j].second * i;
    }

    cout << ans << endl;
    
}