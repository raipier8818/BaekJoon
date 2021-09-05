#include <bits/stdc++.h>
using namespace std;

int t;
int n;
vector<int> A;
vector<int> sum_A;
int m;
vector<int> B;
vector<int> sum_B;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    cin >> n;
    A.resize(n);
    sum_A.resize(n+1);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cin >> m;
    B.resize(m);
    sum_B.resize(m+1);
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }
    

    int start_a = 0;
    int end_a = n;
    
    int total_sum;
    
    sum_A[1] = A[0];
    for(int i = 2; i <= n; i++){
        sum_A[i] = sum_A[i-1] + A[i-1];
    }

    sum_B[1] = B[0];
    for(int i = 0; i < m; i++){
        sum_B[i] = sum_B[i-1] + B[i-1];
    }

    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            total_sum = sum_A[j] - sum_A[i];
            if(total_sum >= t) continue;

            for(int k = 0; k < m; k++){
                for(int l = k + 1; l <= m; l++){
                    total_sum +=
                }
            }

        }
    }
    
}