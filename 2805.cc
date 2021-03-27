#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<long long> trees;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    trees.resize(n);

    long long left = 0;
    long long right = 0;
    
    for(int i = 0; i < n; i++){
        cin >> trees[i];
        right = max(right, trees[i]);
    }

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long temp = 0;
        for(int i = 0; i < n; i++){
            temp += trees[i] - mid > 0 ? trees[i] - mid : 0;
        }

        if(temp >= m){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << right << endl;
    
}