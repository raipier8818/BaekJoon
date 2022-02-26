#include <bits/stdc++.h>

using namespace std;

int num;
double e,w,s,n;

int countAll = 0;
int countSimple = 0;

int board[29][29];

double p = 0;

void calculate(int E,int W,int S,int N){
    cout << E << W << S << N << p << "\n";

    p += (pow(e,E)*pow(w,W)*pow(s,S)*pow(n,N));
}


void find(int E, int W, int S, int N, int C){
    if (C == num){
        calculate(E,W,S,N);
        return;
    }

    cout << board[14+N-S][14+E-S] << "\n";

    if(board[14+N-S+1][14+E-W] == 0){
        board[14+N-S+1][14+E-W] = 1;
        find(E,W,S,N+1,C+1);
        board[14+N-S+1][14+E-W] = 0;
    }
    if(board[14+N-S-1][14+E-W] == 0){
        board[14+N-S-1][14+E-W] = 1;
        find(E,W,S+1,N,C+1);
        board[14+N-S-1][14+E-W] = 0;
    }
    if(board[14+N-S][14+E-W+1] == 0){
        board[14+N-S][14+E-W+1] = 1;
        find(E+1,W,S,N,C+1);
        board[14+N-S][14+E-W+1] = 0;
    }
    if(board[14+N-S][14+E-W-1] == 0){
        board[14+N-S][14+E-W-1] = 1;
        find(E,W+1,S,N,C+1);
        board[14+N-S][14+E-W-1] = 0;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(11);

    cin >> num >> e >> w >> s >> n;
    
    e/=100;
    w/=100;
    s/=100;
    n/=100;

    board[14][14] = 1;
    find(0,0,0,0,0);
    cout << p << "\n";

}