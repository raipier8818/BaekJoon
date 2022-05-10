#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll left;
    ll right;
    ll max;
    ll sum;    
};

struct point{
    int x;
    int y;
    ll val;
};

int n;
point arr[3001];
node seg[1 << 20];
map<int, vector<point>> mp;

node merge(const node& l, const node& r){
    return {
        max({l.sum + r.left, l.left}),
        max({r.right, r.sum + l.right}),
        max({l.right + r.left, l.max, r.max, 
            max({l.sum + r.left, l.left}),
            max({r.right, r.sum + l.right})
        }),
        l.sum + r.sum
    };
}


void update(int l, int r, int pos, int val, int I){
    if(pos < l || r < pos) return;
    if(l == r){
        seg[I] = {val, val, val, val};
        return;
    }

    int mid = l + r >> 1;
    update(l, mid, pos, val, I << 1);
    update(mid + 1, r, pos, val, I << 1 | 1);

    seg[I] = merge(seg[I << 1], seg[I << 1 | 1]);
}

ll query(){
    return max({
        seg[1].left,
        seg[1].right,
        seg[1].max
    });
}

void initSeg(){
    for(int i = 1; i <= 4*n; i++){
        seg[i] = {-1000000001,-1000000001,-1000000001,0};
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].val;
        mp[arr[i].y].push_back(arr[i]);
    }

    sort(arr + 1, arr + n + 1, [](point& a, point& b){
        return a.y < b.y;
    });

    ll ans = 0;
    int ty = -1000000001;
    for(int i = 1; i <= n; i++){
        
    }    

    cout << ans << endl;
}
