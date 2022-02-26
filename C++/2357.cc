#include <iostream>
#include <vector>
#define ll long long
#define INF 98765432100;

ll n,m;

using namespace std;


class segtree{
    public:
    vector <ll> tree;
    ll size;

    segtree(ll n){
        for (size = 1; size < n; size *= 2);
        tree.resize(2*size);
    }

    void updateMin(ll pos, ll x){
        ll index = size + pos - 1;
        tree[index] = INF;

        ll u = min(x,tree[index]);

        while (index){
            if (!tree[index]){
                tree[index] = INF;
            }
            tree[index] = min(u,tree[index]);
            index /= 2;
        }
    }

    void updateMax(ll pos, ll x){
        ll index = size + pos - 1;
        ll u = max(x,tree[index]);
        while (index){
            tree[index] = max(u,tree[index]);
            index /= 2;
        }
    }

    ll getMin(ll pos, ll L, ll R, ll start, ll end){
        if (R < start || L > end){
            return INF;
        }

        if (L <= start && R >= end) return tree[pos];

        ll mid = (start + end) / 2;
        return min(getMin(pos*2, L, R, start, mid), getMin(pos*2+1,L,R,mid+1,end));
    }

    ll getMax(ll pos, ll L, ll R, ll start, ll end){
        if (R < start || L > end){
            return 0;
        }

        if (L <= start && R >= end) return tree[pos];

        ll mid = (start + end) / 2;
        return max(getMax(pos*2, L, R, start, mid), getMax(pos*2+1,L,R,mid+1,end));
    }
};

int main(){

    scanf("%lld %lld", &n,&m);
    segtree TreeMax(n);
    segtree TreeMin(n);

    for(ll i = 1; i <= n; i++){
        ll num;
        scanf("%lld", &num);
        TreeMax.updateMax(i,num);
        TreeMin.updateMin(i,num);
    }

    for(ll i = 0; i < m; i++){
        ll a,b;
        scanf("%lld %lld", &a, &b);
        printf("%lld %lld\n", TreeMin.getMin(1,a,b,1,TreeMin.size), TreeMax.getMax(1,a,b,1,TreeMax.size));
    }
    
}