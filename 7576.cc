#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[1000][1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> bfs;


    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                bfs.push(make_pair(i, j));
        }
    }

    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    while (!bfs.empty())
    {
        int posX = bfs.front().first;
        int posY = bfs.front().second;

        bfs.pop();

        for (int i = 0; i < 4; i++) {
            int newX = posX + dx[i];
            int newY = posY + dy[i];

            if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
            if (arr[newX][newY] == 0) {
                bfs.push(make_pair(newX, newY));
                arr[newX][newY] = arr[posX][posY] + 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
            answer = max(answer, arr[i][j]);
        }
    }

    cout << answer - 1;
}