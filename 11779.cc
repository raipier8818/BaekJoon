#include <bits/stdc++.h>
using namespace std;

int n,m;

int s, e;
int bus[1001][1001];

bool v[1001];
priority_queue<pair<int,pair<int,int>>> r;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;

    memset(bus, 100001, sizeof(bus));

    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        bus[a][b] = c;
    }


    cin >> s >> e;
    vector<int> route;

    int CurrentPos = s;
    int Cost = 0;

    while(true){
        int minIdx = 0;
        route.push_back(CurrentPos);
        v[CurrentPos] = true;
        for(int i = 1; i <= n; i++){
            if(bus[CurrentPos][i] == 100001 || v[i] == true) continue;

            if(bus[CurrentPos][minIdx] > bus[CurrentPos][i]){
                minIdx = i;
            }
            
        }

        CurrentPos = minIdx;
    }


}