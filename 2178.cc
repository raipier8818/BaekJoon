#include <bits/stdc++.h>
using namespace std;

int maze[100][100];
int v[100][100];

int n, m, ct;
queue <pair<int, int>> bfs;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };


bool check(int nr, int nc) {
    if (0 <= nr && nr < n && 0 <= nc && nc < m) {
        if (maze[nr][nc] == 1 && v[nr][nc] == 0) {
            return true;
        }
    }
    return false;
}


void f(int count) {
    bfs.push(make_pair(0, 0));
    while (!bfs.empty()) {
        int curX = bfs.front().first;
        int curY = bfs.front().second;

        bfs.pop();

        for (int i = 0; i < 4; i++) {
            int nX = curX + dr[i];
            int nY = curY + dc[i];


            if (check(nX, nY)) {
                v[nX][nY] = v[nX][nY] == 0 ? v[curX][curY] + 1 : min(v[curX][curY] + 1, v[nX][nY]);
                bfs.push(make_pair(nX, nY));
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            maze[i][j] = row[j] - '0';
        }
    }
    v[0][0] = 1;
    f(1);
    cout << v[n - 1][m - 1] << endl;

}