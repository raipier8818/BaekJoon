#include <bits/stdc++.h>
using namespace std;

int n, t;
int arr[1000];

int main(){
    cin >> n >> t;
    
    int arm = 0;
    bool up = true;
    
    for(int i = 0; i < t; i++){
        if(up) {
            arm += 1;
            if(arm == n*2) up = false;
        }
        else{
            arm -= 1;
            if(arm == 1) up = true;
        }
        
    }
    cout << arm << endl;
}