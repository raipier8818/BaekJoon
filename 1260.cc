#include <bits/stdc++.h>
using namespace std;

int n,m,v;
vector<vector<int>> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;

    arr.resize(n+1);

    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    int visit_[1001];

    queue<int> dfs;
    




    int visit[1001];

    stack<int> bfs;
    bfs.push(1);

    while (!bfs.empty())
    {
        int pos = bfs.top();
        visit[pos] = 1;
        bfs.pop();


        cout << pos << " ";

        for(int i = 0; i < arr[pos].size(); i++){
            if(visit[arr[pos][i]] == 1) continue;        
            sort(arr[i].begin(), arr[i].end(), greater<int>());
            bfs.push(arr[pos][i]);
            visit[arr[pos][i]] = 1;
        }
    }
    cout << "\n";


}