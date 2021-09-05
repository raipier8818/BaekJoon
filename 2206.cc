#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
int visited[1001][1001];
vector<pair<int,int>> v;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int answer;

bool checkPoint(int nx, int ny){
    return !(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] == 1);
}


void dfs(pair<int,int> w1, pair<int,int> w2, pair<int,int> w3, pair<int,int> cur, int count){
    // cout << "// " << cur.first << " " << cur.second << endl;
    if(cur.first == n - 1 && cur.second == m - 1){
        answer = max(answer, count);
        return;
    }

    cout << "// " << cur.first << " " << cur.second << endl;

    int temp[1001][1001];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = arr[i][j];
        }
    }

    temp[w1.first][w1.second] = 0;
    temp[w2.first][w2.second] = 0;
    temp[w3.first][w3.second] = 0;

    for(int i = 0; i < 4; i++){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if(checkPoint(nx, ny) && temp[nx][ny] == 0){
            visited[nx][ny] = 1;
            dfs(w1, w2, w3, make_pair(nx, ny), count + 1);
            visited[nx][ny] = 0;
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        
        // cout << row << endl; 

        for(int j = 0; j < m; j++){
            if(row[j] == '0'){
                arr[i][j] = 0;
            }else{
                arr[i][j] = 1;
                v.push_back(make_pair(i,j));
            }
        }
    
    }

    for(int i = 0; i < v.size() - 2; i++){
        for(int j = i + 1; j < v.size() - 1; j++){
            for(int k = j + 1; k < v.size(); k++){
                // cout << "//" << i << " " << j << " " << k << endl;
                memset(visited, 0, sizeof(visited));

                dfs(v[i], v[j], v[k], make_pair(0,0), 0);
            }
        }
    }

    cout << answer;


}