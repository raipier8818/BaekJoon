#include <bits/stdc++.h>
using namespace std;

int t,m,n,k,x,y;
int arr[50][50];
bool v[50][50];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int cnt;

void find(int start_x, int start_y){
    for(int i = 0; i < 4; i++){
        int newX = start_x + dx[i];
        int newY = start_y + dy[i];
        

        if(newX >= 0 && newX < n && newY >= 0 && newY < m){
            if(arr[newX][newY] == 1 && v[newX][newY] == false){
                v[newX][newY] = true;
                find(newX,newY);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        memset(arr,0,sizeof(arr));
        memset(v,false,sizeof(v));
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            arr[y][x] = 1;
        }

        cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //cout << "//" << i << " " << j << endl;
                if(arr[i][j] == 1 && v[i][j] == false) {
                    
                    v[i][j] = true;
                    find(i,j);
                    
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
}