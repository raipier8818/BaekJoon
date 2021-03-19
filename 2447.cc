#include <bits/stdc++.h>

using namespace std;

int n;
char arr[10000][10000];

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

void draw(int x, int y, int size){
    if(size <= 1) {
        return;
    }

    for(int i = x + size/3; i < x + 2*size/3; i++){
        for(int j = y + size/3; j < y + 2*size/3; j++){
            arr[i][j] = ' ';
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){        
            draw(x + i*(size/3),y + j*(size/3),size/3);
        }
    }

}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = '*';
        }
    }
    draw(0,0,n);
    print();
}