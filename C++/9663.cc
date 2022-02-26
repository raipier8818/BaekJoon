#include <iostream>
using namespace std;

int n;
int row[15];
int count;


int check(int y){

    for(int i = 0; i < y; i++){
        int len = row[i] - row[y];
        if (len < 0){
            len *= -1;
        }

        if (row[i] == row[y] or len == y - i){
            return 0;
        }
    }
    return 1;
}

void find(int y){
    if(y == n){
        count += 1;
        return;
    }
    
    for (int x = 0; x < n; x++){
        row[y] = x;
        if (check(y)){
            find(y+1);
        }
    }
}

int main(){
    cin >> n;
    find(0);
    cout << count;
}





/*
n = int(input())

row = [0 for _ in range(n)]


count = 0

def check(y):
    for i in range(y):
        if row[i] == row[y] or abs(row[i] - row[y]) == y - i:
            return False
    return True


def find(y):
    global count
    if y == n:
        count += 1
        return

    for x in range(n):
        row[y] = x
        if check(y):
            find(y+1)

find(0)
print(count)
*/