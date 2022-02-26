#include <stdio.h>

#define ll long long
#define MAX 1000000


ll MOD = 1000000007;

ll n,m,k;

ll tree[4000000];

ll update(ll index, ll target, ll value, ll start, ll end){
    if (start > target || end < target) return tree[index];
    if (start == end) return tree[index] = value;
    ll mid = (start + end) /2;
    return tree[index] = ((update(index*2,target,value,start,mid)%MOD) * (update(index*2+1,target,value,mid+1,end)%MOD)) % MOD;
}

ll getmul(ll pos, ll left, ll right, ll start, ll end){
    if( right < start || left > end ){
        return 1;
    }
    if ( start >= left && end <= right){
        return tree[pos];
    }
    ll mid = (start+end)/2;
    return ((getmul(pos*2,left,right,start,mid)%MOD) * (getmul(pos*2+1,left,right,mid+1,end)%MOD))%MOD;
}


int main(){
    scanf("%lld %lld %lld", &n,&m,&k);
    
    for(int i = 1; i <= n; i++){
        int num;
        scanf("%d",&num);
        update(1,i,num,1,n);
    }

    for(ll i = 0; i < m+k; i++){
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        if (a == 1) update(1,b,c,1,n);
        else printf("%lld\n", getmul(1,b,c,1,n)%MOD);
    }

    return 0;
}