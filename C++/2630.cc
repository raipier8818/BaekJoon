#include <bits/stdc++.h>
using namespace std;

int n;
int arr[128][128];

int count_white, count_blue;


void find(int start_row, int start_col, int size){
    //cout << "// " << start_row << " " << start_col << " " << size << endl;


    if(size == 1){
        if(arr[start_row][start_col] == 1) count_blue++;
        else count_white++;
        return;
    }

    bool check_white = true;
    bool check_blue = true;
    for(int i = start_row; i < start_row + size; i++){
        for(int j = start_col; j < start_col + size; j++){
            if(arr[i][j] == 1){
                check_white = false;
            }
            if(arr[i][j] == 0){
                check_blue = false;
            }
        }
    }
    if(check_blue){
        count_blue++;
        return;
    }
    if(check_white){
        count_white++;
        return;
    }
    for(int i = 0; i < size; i += size/2){
        for(int j = 0; j < size; j += size/2){
            find(start_row + i, start_col + j, size/2);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    find(0,0,n);
    cout << count_white << "\n";
    cout << count_blue << "\n";
}