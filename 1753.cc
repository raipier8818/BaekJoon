#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int,int>>> graph;
priority_queue<pair<ll,int>> pq;
ll visit[20001];


int V,E,K;
int u,v,w;

void dijkstra(){
    memset(visit, -1, sizeof(visit));
    visit[K] = 0;

    pq.push(make_pair(0,K));
    
    while(!pq.empty()){
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;

    for(int i = 0; i < V + 1; i++){
        vector<pair<int,int>> node;
        graph.push_back(node);
    }

    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }
    
    dijkstra();
    cout << visit[K];
}