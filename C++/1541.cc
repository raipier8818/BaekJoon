#include <bits/stdc++.h>
using namespace std;

string A;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A;
    int answer = 0;

    int num = 0;
    bool plus = true;
    for(int i = 0; i < A.size(); i++){
        if(A[i] >= 48 && A[i] <= 57){
            num *= 10;
            num += A[i] - 48;
        }else{
            //cout << num << endl;

            if(plus) answer += num;
            else answer -= num;
            num = 0;

            if(A[i] == '-') plus = false;
        }

    }

    if(plus) answer += num;
    else answer -= num;
    cout << answer << "\n";

}