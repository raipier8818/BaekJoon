#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> matrix;

int n;
long long b;

matrix operator*(const matrix &lhs, const matrix &rhs){
    long long size = lhs.size();

    matrix res(size,vector<long long>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                res[i][j] += lhs[i][k] * rhs[k][j];
            }
            res[i][j] %= 1000;
        }
    }

    return res;
}

matrix multiMatrix(matrix a, long long n){
    long long size = a.size();
    matrix res(size, vector<long long>(size));

    for(int i = 0; i < size; i++){
        res[i][i] = 1;
    }

    while(n > 0){
        if(n % 2 == 1){
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }

    return res;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;

    matrix a(n,vector<long long>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    a = multiMatrix(a,b);
    for(int i = 0; i < n; i++){
        for(int j  = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

}