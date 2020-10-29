#include <iostream>
int row[10][10];
int n,count;

using namespace std;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> row[i][j];
        }
    }
}