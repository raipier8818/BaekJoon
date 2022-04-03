#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int sudoku[9][9];
vector<pair<int, int> > v;

bool check(int row, int col){
    int temp[10];
    memset(temp, 0, sizeof(temp));

    for(int i = 0; i < 9; i++){
        temp[sudoku[row][i]]++;
        temp[sudoku[i][col]]++;
        temp[sudoku[row/3*3+i/3][col/3*3+i%3]]++;
    }

    for(int i = 1; i <= 9; i++){
        if(temp[i] > 3) return false;
    }

    return true;
}

void findsudoku(int idx){
    if(idx == v.size()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        exit(0);
        return;
    }

    for(int i = 1; i <= 9; i++){
        sudoku[v[idx].first][v[idx].second] = i;
        if(check(v[idx].first, v[idx].second)){
            findsudoku(idx+1);
        }
    }
    sudoku[v[idx].first][v[idx].second] = 0;
}

int main(){

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) v.push_back(make_pair(i, j));
        }
    }

    findsudoku(0);
}