#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;



int n, m;
int maze[100][100];
int visit[100][100];



int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int d[100][100];


int checkpos(int x, int y) {
    if (x >= 0 && x < m && y >= 0 && y < n) return 1;
    else return 0;
}

void dijkstra(int start) {
    d[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    visit[0][0] = 1;

    while (!pq.empty()) {
        int cur_x = pq.top().second.first;
        int cur_y = pq.top().second.second;
        int val = pq.top().first * -1;
        pq.pop();

        if (d[cur_y][cur_x] < val) continue;

        for (int i = 0; i < 4; i++) {
            int NextX = dx[i] + cur_x;
            int NextY = dy[i] + cur_y;


            if (checkpos(NextX, NextY) && visit[NextX][NextY] != 1) {
                int NextD = val + maze[NextY][NextX];
                d[NextY][NextX] = NextD;

                visit[NextX][NextY] = 1;
                pq.push(make_pair(NextD * -1, make_pair(NextX, NextY)));
            }


        }
    }

}





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) d[i][j] = 987654321;
    }

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++) {
            maze[i][j] = Inp[j] - '0';
        }
    }

    dijkstra(0);
    cout << d[n - 1][m - 1];

}