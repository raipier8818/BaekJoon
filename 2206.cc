#include <bits/stdc++.h>

int n,m;
int arr[1000][1000];
int visit[1000][1000];
int minNum = __INT_MAX__;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check = 0;

/*
void find(int x, int y, int wall, int count){
    //printf("// %d %d %d // \n", x, y, wall);
    
    if(x == m-1 && y == n-1){
        //printf("c : %d\n",count);
        minNum = std::min(minNum,count);
        check = 1;
        return;
    }

    for(int i = 0; i < 4; i++){
        int X = x + dx[i];
        int Y = y + dy[i];

        if(0 <= X && X < m && 0 <= Y && Y < n){
            if(arr[Y][X] == 0 && visit[Y][X] == 0){
                visit[Y][X] = 1;
                find(X,Y,wall,count+1);
                visit[Y][X] = 0; 
            }

            else if(arr[Y][X] == 1 && wall > 0 && visit[Y][X] == 0){
                visit[Y][X] = 1;
                find(X,Y,wall-1,count+1);
                visit[Y][X] = 0;
            }
        }

    }
    


}
*/


int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;

    for(int i = 0; i < n; i++){
        std::string a;
        std::cin >> a;
        for(int j = 0; j < m; j++){
            arr[i][j] = a[j] - '0';
        }
    }

    arr[0][0] = 1;
    visit[0][0] = 1;

    find(0,0,1,1);
    if (check == 0) std::cout << -1 << "\n";
    else std::cout << minNum << "\n";
}