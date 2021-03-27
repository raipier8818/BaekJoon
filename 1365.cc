#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.resize(n);
    for(int i = 0;i < n; i++)
    {
        cin >> arr[i];
    } 

    vector<int> lis;
    for(int i = 0; i < n; i++){
        int idx = lower_bound(lis.begin(),lis.end(), arr[i]) - lis.begin();
        if(idx == lis.size()){
            lis.push_back(arr[i]);
        }else{
            lis[idx] = arr[i];
        }
    }

    cout << n-lis.size();
}