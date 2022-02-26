#include <bits/stdc++.h>
using namespace std;

int n,m,k;

int A[100][100];
int B[100][100];

int C[100][100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    
    cin >> m >> k;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            for(int l = 0; l < m; l++){
                C[i][j] += A[i][l]*B[l][j]; 
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}