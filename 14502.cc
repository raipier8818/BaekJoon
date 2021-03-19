#include <bits/stdc++.h>
using namespace std;

int n,m;

int institute[8][8];
int wall[3][2];

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void findWall(int r, int c, int count){
    if(count == 3) return;
    if(0 <= r && r < n && 0 <= c && c < m){
        if(institute[r][c] == 0){
            for(int i = 0; i < 4; i++){
                
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> institute[i][j];
        }
    }    

}