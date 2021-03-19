#include <bits/stdc++.h>
using namespace std;
#define ll long long


int n,b;
ll matrix[5][5];
ll origin[5][5];

void multi_matrix(ll n){
    if(n == 1) return;
    if(n % 2 == 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    matrix[i][j] += matrix[i][k] * matrix[k][j];
                    matrix[i][j] %= 1000;
                }
            }
        }
        multi_matrix(n/2);
    }
    if(n % 2 == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    matrix[i][j] += origin[i][k] * origin[k][j];
                    matrix[i][j] %= 1000;
                }
            }
        }
        multi_matrix(n-1);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            origin[i][j] = matrix[i][j];
        }
    }
    multi_matrix(b);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}