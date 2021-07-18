#include <bits/stdc++.h>
using namespace std;

long long n,m,k;
long long a,b,c;

long long segtree[4000001];

int idx;

void insert(long long val, long long i){
    segtree[i] = val;
    while(i != 1){
        segtree[i/2] = segtree[(i/2)*2] + segtree[(i/2)*2+1];
        i/=2;
    }
}

long long find(long long start, long long end, long long S, long long E, long long index){
    if(start > E || end < S) return 0;
    else if(start >= S && end <= E){
        return segtree[index];
    }
    else{
        return find(start, (start + end) / 2, S, E, index * 2) + find((start + end) / 2 + 1, end, S, E, index*2 + 1);
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(idx = 1; idx < n; ) idx *= 2;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        insert(num, i + idx);
    }

    m += k;
    while(m--){
        cin >> a >> b >> c;
        if(a == 1){
            insert(c, idx + b - 1);
        }
        else{
            cout << find(1, idx, b,c,1) << "\n";
        }
    }
}