#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll seg[1 << 18];
ll lazy[1 << 18];
ll arr[100001];

void build(int l, int r, int I = 1){
    // if(l > pos || r < pos) return;
    if(l == r){ 
        seg[I] = arr[l];
        return;
    }

    int mid = l + r >> 1;
    build(l, mid, I << 1);
    build(mid + 1, r, I << 1 | 1);

    seg[I] = seg[I << 1] + seg[I << 1 | 1];
}

void lazyUpdate(int l, int r, int I){
    seg[I] += (r - l + 1LL) * lazy[I];
    if(l != r){
        lazy[I << 1] += lazy[I];
        lazy[I << 1 | 1] += lazy[I];
    }
    lazy[I] = 0;
}

void query(int l, int r, int pos, int I = 1){
    lazyUpdate(l, r, I);
    if(l > pos || r < pos) return;
    if(l == pos && r == pos){
        cout << seg[I] << "\n";
        return;
    }

    int mid = l + r >> 1;
    query(l, mid, pos, I << 1);
    query(mid + 1, r, pos, I << 1 | 1);
}

void update(int l, int r, int x, int y, int val, int I = 1){
    lazyUpdate(l, r, I);
    if(l > y || r < x) return;
    if(x <= l && r <= y){
        lazy[I] += (ll)val;
        lazyUpdate(l, r, I);
        return;
    }

    int mid = l + r >> 1;
    update(l, mid, x, y, val, I << 1);
    update(mid + 1, r, x, y, val, I << 1 | 1);

    seg[I] = seg[I << 1] + seg[I << 1 | 1];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    build(1, n, 1);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a,b,c,d;
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            update(1, n, b, c, d, 1);
        }else{
            cin >> b;
            query(1, n, b, 1);
        }
    }
}
