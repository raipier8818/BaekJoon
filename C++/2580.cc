#include <bits/stdc++.h>
using namespace std;

int board[9][9];
int zero[9][9];

vector<pair<int,int>> zeroPoint;


void find(pair<int,int> point, int idx){
    if(idx == zeroPoint.size()){
        for (int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }

    cout << " // " << point.first << " " << point.second << "\n";

    int check[10] = {0,0,0,0,0,0,0,0,0,0};
    
    for(int i = 0; i < 9; i++){
        check[board[i][point.second]] = 1;
    }
    for(int i = 0; i < 9; i++){
        check[board[point.first][i]] = 1;
    }
    for(int i = point.first; i < point.first + 3; i++){
        for(int j = point.second; j < point.second + 3; j++){
            check[board[i][j]] = 1;
        }
    }

    stack<int>val;
    for(int i = 1; i <= 9; i++){
        if(check[i] == 0) val.push(i);
    }

    while (!val.empty())
    {
        int v = val.top();
        val.pop();

        board[point.first][point.second] = v;
        find(zeroPoint[idx+1], idx+1);
        board[point.first][point.second] = 0;
    }
}




int main(){
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) zeroPoint.push_back(make_pair(i,j));
        }
    }
    find(zeroPoint[0],0);
}