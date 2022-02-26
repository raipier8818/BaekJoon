#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class segtree{
    public:
    vector<ll> tree;
    vector<ll> lazy;
    int size;

    segtree();
    segtree(int n){
        for(size = 1; size < n; size *= 2);
        tree.resize(size*2+1);
        lazy.resize(size*2+1);
    }

    void update_plus(int now, int start, int end, int idx, ll diff){
        if(idx < start || idx > end) return;
        tree[now] += diff;

        if(start != end){
            int mid = (start+end)/2;
            update_plus(now*2,start,mid,idx,diff);
            update_plus(now*2+1,mid+1,end,idx,diff);
        }
    }

    void update_lazy(int now, int start, int end){
        if(lazy[now] != 0){
            tree[now] += (end-start+1)*lazy[now];

            if(start != end){
                lazy[now*2] += lazy[now];
                lazy[now*2+1] += lazy[now];
            }
            lazy[now] = 0;
        }

    }

    void update_range(int now, int start, int end, int left, int right, ll diff){
        
        update_lazy(now, start,end);
        
        if(right < start || left > end) return;
        if(left <= start && right >= end){
            tree[now] += (end-start+1)*diff;

            if(start != end){
                lazy[now*2] += diff;
                lazy[now*2+1] += diff;
            }
            return;
        }        

        int mid = (start+end)/2;

        update_range(now*2,start,mid,left,right,diff);
        update_range(now*2+1,mid+1,end,left,right,diff);

        tree[now] = tree[now*2] + tree[now*2+1];
        return;
    }

    ll getsum(int idx, int start, int end, int left, int right){
        update_lazy(idx,start,end);
        if(start > right || end < left){
            return 0;
        }
        if(left <= start && right >= end){
            return tree[idx];
        }

        int mid = (start+end)/2;
        return getsum(idx*2,start,mid,left,right) + getsum(idx*2+1,mid+1,end,left,right);

    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    segtree Tree(n);
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        Tree.update_plus(1,1,Tree.size,i,num);
    }

    for(int i =0 ; i < m+k; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            ll d;
            cin >> d;

            Tree.update_range(1,1,Tree.size,b,c,d);
        }
        else{
            cout << Tree.getsum(1,1,Tree.size,b,c) << endl;
        }
    }

    return 0;
}