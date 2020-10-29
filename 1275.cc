#include <iostream>
#include <vector>
#include <stdio.h>
#define ll long long
ll n,m,k;

using namespace std;


class segtree{
    public:
    vector <ll> tree;
    ll size;

    segtree(ll n){
        for (size = 1; size < n; size *= 2);
        tree.resize(2*size);
    }

    void update(ll pos, ll x){
        ll index = size + pos - 1;
        ll u = x - tree[index];

        while (index){
            tree[index] += u;
            index /= 2;
        }
    }

    ll getsum(ll pos, ll left, ll right, ll start, ll end){
        if (right < start || left > end){
            return 0;
        }

        if (start >= left && end <= right){
            return tree[pos];
        }

        ll mid = (start + end) / 2;
        return getsum(pos * 2, left, right, start, mid) + getsum(pos * 2 + 1, left, right, mid+1, end);
    }

};
int main(){
    scanf("%lld %lld", &n,&m);
    segtree Arr(n);

    for(ll i = 1; i <= n; i++){
        ll num;
        scanf("%lld",&num);
        Arr.update(i, num);
    }

    for(ll i = 0; i < m; i++){
        ll x,y,a, b;
        scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
        if (x<y){
            printf("%lld\n",Arr.getsum(1,x,y,1,Arr.size));

        }else{
            printf("%lld\n",Arr.getsum(1,y,x,1,Arr.size));

        }
        Arr.update(a,b);
    }    

}