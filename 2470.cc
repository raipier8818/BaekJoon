#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    int start = 0;
    int end = n - 1;
    int ans = INT_MAX;

    int left = 0;
    int right = 0;
    while(start < end){
        int temp = v[start] + v[end];
        // cout << temp << endl;
        if(abs(temp) < ans){
            ans = abs(temp);
            left = v[start];
            right = v[end];
        }
        if(temp < 0){
            start++;
        }
        else if(temp > 0){
            end--;
        }
        else break;
    }

    cout << left << " " << right << endl;
}