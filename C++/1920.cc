#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> arr;

bool binary_search(int start, int end, long long target){
    if(start > end) return false;
    
    int mid = (start + end) / 2;

    if(arr[mid] == target) return true;

    bool check = false;
    if(arr[mid] < target) check = find(mid + 1, end, target);
    if(arr[mid] > target) check = find(start, mid-1, target);

    return check;
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.resize(n);
    for(int i = 0;i < n; i++){
        long long num;
        cin >> num;
        arr[num] += 1;
    }
    
    sort(arr.begin(), arr.end());
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        long long num;
        cin >> num;
        if(binary_search(0,n,num)) cout << 1 << "\n";
        else cout << 0 << "\n";
    } 

}