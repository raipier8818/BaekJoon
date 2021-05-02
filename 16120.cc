#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A;
    cin >> A;
    int pCount = 0;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == 'P'){
            pCount++;
        }
        else if(A[i] == 'A'){
            if(A[i+1] == 'P' && pCount >= 2){
                pCount--;
                i++;
            }else{
                cout << "NP";
                return 0;
            }
        }else{
                cout << "NP";
                return 0;
        }
    }

    if(pCount == 1) cout << "PPAP";
    else cout << "NP";
}