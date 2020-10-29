#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <climits>

#define INF 987654321

using namespace std;

int n,m,a,b,c;
int A,B;

int d[1001];
vector <pair<int,int>> city[100001];

void dijkstra(int start){
    d[start] = 0;
    priority_queue <pair<int,int>> pq;
    pq.push(make_pair(d[start],start));

    while(!pq.empty()){
        int current = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        if(d[current] < dis) continue;

        for(int i = 0; i < city[current].size(); i++){
            int next = city[current][i].first;
            int nextD = dis + city[current][i].second;

            if(nextD < d[next]){
                d[next] = nextD;
                pq.push(make_pair(nextD,next));
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++) d[i] = INF;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        city[a].push_back(make_pair(b,c));
    }

    cin >> A >> B;

    dijkstra(A);

    cout << d[B] << endl;
    
}