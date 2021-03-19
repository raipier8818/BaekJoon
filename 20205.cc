#include <bits/stdc++.h>

using namespace std;

int arr[10][10];

int main(){
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n*k ; i++){
        for(int j = 0; j < n*k; j++){
            cout << arr[i/k][j/k] << " ";
        }
        cout << endl;
    }


}