#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<long long> arr_positive;
vector<long long> arr_negative;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr_positive.resize(10000001);
    arr_negative.resize(10000001);

    for(long long i = 0; i < n; i++){
        long long idx;
        cin >> idx;

        if(idx >= 0) arr_positive[idx]++;
        else arr_negative[-1*idx]++;  
    }

    cin >> m;
    for(long long i = 0; i < m; i++){
        long long num;
        cin >> num;
        if(num >= 0) cout << arr_positive[num] << " "; 
        else cout << arr_negative[-1*num] << " ";
    }

}