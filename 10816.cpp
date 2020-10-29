#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10000000*2+1];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[num+10000000] += 1;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        cout << arr[num+10000000] << "\n";
    }


}