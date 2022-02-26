#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> B;

int n;

bool comp(int left, int right){
    return left > right ? 1 : 0;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    A.resize(n);
    B.resize(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    sort(A.begin(),A.end(),comp);
    sort(B.begin(),B.end());

    int answer = 0;
    for(int i = 0; i < n; i++){
        answer += A[i]*B[i];
    }

    cout << answer << "\n";
}