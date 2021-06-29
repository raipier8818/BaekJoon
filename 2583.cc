#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a, b, c, d;

int arr[101][101];
int v[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> area;

int area_count = 0;

void find(int x, int y, int a)
{
    if (x < 0 || x > n || y < 0 || y > m || v[y][x] == 1 || arr[y][x] == 1)
        return;
    v[y][x] == 1;
    area_count = a;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        find(nx, ny, a + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while (k--)
    {
        cin >> a >> b >> c >> d;
        for (int i = a; i < c; i++)
        {
            for (int j = b; j < d; j++)
            {
                arr[j][i] = 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[j][i] == 0 && v[j][i] == 0)
            {
                answer += 1;
                find(i, j, 0);
                area.push_back(area_count);
            }
        }
    }

    cout << "asdfasdf";
}