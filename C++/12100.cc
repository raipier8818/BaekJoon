#include <bits/stdc++.h>
using namespace std;

int arr[21][21];
int visited[21][21];

int n;
int answer;

typedef struct _point {
    int row;
    int col;
}point;

int find_max() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, visited[i][j]);
        }
    }
    return ans;
}

void rotate_clockwise() {  //clockwise
    int temp[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = visited[n - 1 - j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = temp[i][j];
        }
    }
}


void rotate_counterclockwise() {  //clockwise
    int temp[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = visited[j][n - 1 - i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = temp[i][j];
        }
    }
}

bool merge_node(point p1, point p2) {
    if (visited[p1.row][p1.col] == 0 || visited[p1.row][p1.col] != visited[p2.row][p2.col]) return false;

    visited[p1.row][p1.col] *= 2;
    visited[p2.row][p2.col] = 0;

    return true;
}

void func_2048(int count) {
    if (count >= 5) {
        answer = max(answer, find_max());
        return;
    }
    int temp[21][21];

    //cout << "-----------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = visited[i][j];
            //cout << temp[i][j] << " ";
        }
        //cout << endl;
    }

    //left
    int row = 0;
    while (row < n) {
        int first = 0;
        while (first < n) {
            int second = first + 1;
            while (second < n) {
                if (merge_node({ row, first }, { row, second })) {
                    first = second;
                }
                second++;
            }
            first++;
        }
        row++;
    }

    for (int row = 0; row < n; row++) {
        int blank = 0;
        for (int i = 0; i < n; i++) {
            if (visited[row][i] != 0) {
                visited[row][blank] = visited[row][i];
                if (blank != i) {
                    visited[row][i] = 0;
                }
                blank++;
            }
        }
    }

    func_2048(count + 1);


    //right
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = temp[i][j];
        }
    }

    rotate_clockwise();
    rotate_clockwise();


    row = 0;
    while (row < n) {
        int first = 0;
        while (first < n) {
            int second = first + 1;
            while (second < n) {
                if (merge_node({ row, first }, { row, second })) {
                    first = second;
                }
                second++;
            }
            first++;
        }
        row++;
    }

    for (int row = 0; row < n; row++) {
        int blank = 0;
        for (int i = 0; i < n; i++) {
            if (visited[row][i] != 0) {
                visited[row][blank] = visited[row][i];
                if (blank != i) {
                    visited[row][i] = 0;
                }
                blank++;
            }
        }
    }

    rotate_clockwise();
    rotate_clockwise();

    func_2048(count + 1);

    //up
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = temp[i][j];
        }
    }

    rotate_counterclockwise();


    row = 0;
    while (row < n) {
        int first = 0;
        while (first < n) {
            int second = first + 1;
            while (second < n) {
                if (merge_node({ row, first }, { row, second })) {
                    first = second;
                }
                second++;
            }
            first++;
        }
        row++;
    }

    for (int row = 0; row < n; row++) {
        int blank = 0;
        for (int i = 0; i < n; i++) {
            if (visited[row][i] != 0) {
                visited[row][blank] = visited[row][i];
                if (blank != i) {
                    visited[row][i] = 0;
                }
                blank++;
            }
        }
    }
    rotate_clockwise();

    func_2048(count + 1);

    //down
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = temp[i][j];
        }
    }

    rotate_clockwise();


    row = 0;
    while (row < n) {
        int first = 0;
        while (first < n) {
            int second = first + 1;
            while (second < n) {
                if (merge_node({ row, first }, { row, second })) {
                    first = second;
                }
                second++;
            }
            first++;
        }
        row++;
    }

    for (int row = 0; row < n; row++) {
        int blank = 0;
        for (int i = 0; i < n; i++) {
            if (visited[row][i] != 0) {
                visited[row][blank] = visited[row][i];
                if (blank != i) {
                    visited[row][i] = 0;
                }
                blank++;
            }
        }
    }

    rotate_counterclockwise();

    func_2048(count + 1);
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = arr[i][j];
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            visited[i][j] = arr[i][j];
        }
    }

    func_2048(0);
    cout << answer;
}