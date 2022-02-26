#include <bits/stdc++.h>
using namespace std;

int n;
bool area[100][100][101];
int ans = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool point_validation(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

bool search_point(int x, int y, int z){
    if(area[x][y][z] == false) return false;
    
    stack<tuple<int,int,int>> s;
    s.push(make_tuple(x,y,z));

    while(!s.empty()){
        tuple<int,int,int> t = s.top();
        s.pop();

        int x = get<0>(t);
        int y = get<1>(t);
        int z = get<2>(t);

        area[x][y][z] = false;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(point_validation(nx, ny) && area[nx][ny][z] == true){
                s.push(make_tuple(nx, ny, z));
            }
        }
    }

    return true;
}

int search_floor(int z){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(search_point(i, j, z)) count++;
        }
    }

    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            for(int k = 1; k <= temp; k++){
                area[i][j][k] = true;
            }
        }
    }

    for(int i = 1; i < 101; i++){
        int temp = search_floor(i);
        if(temp == 0) break;
        ans = max(ans, temp);
    }

    cout << ans << endl;
}