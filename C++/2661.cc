#include <iostream>
#include <string.h>
int n;
using namespace std;

int arr[80];

int check(int l){
    int mid = l/2;
    int check = 0;
    for (int i = 1; i < mid; i++){
        for (int j = 0; j < i; j++){
            if (arr[l-1-j] != arr[l-1-i-j]){
                check = 1;
            }
        }
        if (check == 0){
            return 1;
        }
    }
    return 0;
}

void printArr(int l){
    for (int i = 0; i < l; i++){
        cout << arr[i] ;
    }
    cout << endl;
}

void dfs(int l){
    if (l >= n){
        printArr(l);
        return;
    }


    for(int i = 1; i < 4; i++){
        arr[l] = i;
        if (!check(l+1)){
            dfs(l+1);
        }
    }
    
}



int main(){
    cin >> n;
    dfs(0);
}