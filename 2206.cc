#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[1000][1000];
int v[1000][1000];

int ans = -1;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

queue<pair<pair<int,int>,pair<bool,int>>> pos;

void find(){
    while(!pos.empty())
    {    
        pair<int,int> current = pos.front().first;
        bool wall = pos.front().second.first;
        int count = pos.front().second.second;

        pos.pop();

        int row = current.first;
        int col = current.second;

        
        if(row < 0 || row >= n || col < 0 || col >= m){
            continue;
        }

        if(board[row][col] == 1){
            if(wall == false){
                continue;
            }

            wall = false;
        }

        if(v[row][col] == 1) continue;

        if(row == n-1 && col == m-1){
            //cout << " : " << count << endl;
            ans = max(ans,count);
            continue;
        }

        cout << "// " << row << " " << col << " " << wall << " // " << pos.size() + 1 << " " << count << endl;

        v[row][col] = 1;
        
        for(int i = 0; i < 4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];

            pos.push(make_pair(make_pair(nr,nc),make_pair(wall,count+1)));
        }
    }

    cout << ans << endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    
    for(int i = 0; i < n; i++){
        string row; cin >> row;

        for(int j = 0; j < m; j++){
            board[i][j] = row[j] - 48;
        }
    }

    pos.push(make_pair(make_pair(0,0),make_pair(true,1)));
    find();
}