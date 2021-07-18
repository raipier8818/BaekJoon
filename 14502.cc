#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10][10];
int visited[10][10];
vector<pair<int, int>> v;

int answer = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };



int check() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) count++;
        }
    }
    return count;
}

queue<pair<int, int>> q;

void find_ans(int w1_x, int w1_y, int w2_x, int w2_y, int w3_x, int w3_y) {
    if (arr[w1_x][w1_y] != 0 || arr[w2_x][w2_y] != 0 || arr[w3_x][w3_y] != 0) return;
    


    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = arr[i][j];
        }
    }

    visited[w1_x][w1_y] = 1;
    visited[w2_x][w2_y] = 1;
    visited[w3_x][w3_y] = 1;

    for (int i = 0; i < v.size(); i++) {
        q.push(v[i]);
    }


    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (visited[nx][ny] == 0) {
                visited[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }

    answer = max(answer, check());
}

vector<pair<int, int>> blank;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) v.push_back(make_pair(i, j));
            if (arr[i][j] == 0) blank.push_back(make_pair(i, j));
        }
    }
    
    for (int i = 0; i < blank.size() - 2; i++) {
        for (int j = i + 1; j < blank.size() - 1; j++) {
            for (int k = j + 1; k < blank.size(); k++) {
                find_ans(blank[i].first, blank[i].second, blank[j].first, blank[j].second, blank[k].first, blank[k].second);
            }
        }
    }


    cout << answer;

}