#include <iostream>
#include <vector>
#include <stdio.h>

#define ll long long


using namespace std;

ll n,q;


class fwtree{
    public:
    vector <ll> tree;
    vector <ll> number;
    int size;

    fwtree(ll n){
        for(size = 1; size < n; size *= 2);
        tree.resize(size + 1);
        number.resize(size+1);  
    }

    void update(ll pos, ll x){
        while(pos <= size){
            tree[pos] += x;
            pos += (pos&(-pos));
        }
    }

    ll sum(ll pos){
        ll ret = 0;
        while (pos > 0){
            ret += tree[pos];
            pos -= (pos&(-pos));
        }
        return ret;
    }
};

int main(){
    scanf("%lld %lld", &n, &q);
    
    fwtree Tree(n);
    
    for(int i = 0; i < q; i++){
        ll a,b,c;
        scanf("%lld %lld %lld", &a,&b,&c);

        if(a == 1) Tree.update(b,c);
        else printf("%lld\n",Tree.sum(c)-Tree.sum(b-1));
    }
}