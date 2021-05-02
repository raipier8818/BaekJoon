#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[8][8];

int wall[4][2];
int answer;

int zero_count = 0;

bool check_point(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= m) ? false : true;
}


void bfsfind(){
    int copy[8][8];
    queue<pair<int,int>> bfs;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            copy[i][j] = arr[i][j];
            if(copy[i][j] == 2) bfs.push(make_pair(i,j));
        }
    }

    for(int i = 1; i <= 3; i++){
        copy[wall[i][0]][wall[i][1]] = 1; 
    }

    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(copy[i][j] == 0) temp++;
        }
    }

    if(temp - zero_count != 3) return;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!bfs.empty()){
        //cout << "::" << bfs.size() << endl;
        pair<int,int> cur = bfs.front();
        bfs.pop();
        

        for(int i = 0; i < 4; i++){
            int newX = dx[i] + cur.first;
            int newY = dy[i] + cur.second;

            if(check_point(newX,newY) && copy[newX][newY] == 0){
                bfs.push(make_pair(newX,newY));
                copy[newX][newY] = 2;
            }
        }
    }

    int count = 0;
    cout << "------------------" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << copy[i][j] << " ";
            if(copy[i][j] == 0) count++;
        }
        cout << endl;
    }

    answer = max(answer, count);
}

bool check_wall(int x, int y, int count){
    if(arr[x][y] != 0) return false;
    
    for(int i = 1; i <= count; i++){
        if(wall[count][0] == x && wall[count][1] == y) return false;
    }

    return true;
}

void set_wall(int count){
    if(count == 3) {
        bfsfind();
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!check_wall(i,j,count)) continue;

            wall[count+1][0] = i;
            wall[count+1][1] = j;
            set_wall(count+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) zero_count++;
        }
    }

    set_wall(0);
    cout << answer;
}