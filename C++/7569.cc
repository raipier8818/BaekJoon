#include <bits/stdc++.h>
using namespace std;

int box[100][100][100];
int visit[100][100][100];
int m, n, h;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int check() {
    int result = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (box[i][j][k] == 0) return 0;
                result = max(result, box[i][j][k]);
            }
        }
    }
    return result;
}

bool check_position(int x, int y, int z) {
    if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h) return false;
    if (box[z][x][y] != 0) return false;

    return true;
}


typedef struct {
    int row;
    int col;
    int height;
    int val;
}space;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    queue<space> stack;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                space newspace = { j,k,i,1 };
                if (box[i][j][k] == 1) stack.push(newspace);
            }
        }
    }
    
    while (!stack.empty()) {
        space cur = stack.front();
        stack.pop();

        for (int i = 0; i < 6; i++) {
            int newX = cur.row + dx[i];
            int newY = cur.col + dy[i];
            int newZ = cur.height + dz[i];

            if (check_position(newX, newY, newZ)) {
                box[newZ][newX][newY] = cur.val + 1;
                space newspace = { newX,newY,newZ,cur.val + 1 };

                stack.push(newspace);
            }
        }
    }


    cout << check() - 1;

}