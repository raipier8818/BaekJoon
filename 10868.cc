#include <stdio.h>
#include <iostream>
#include <limits.h>
#define ll long long
#define MAX LLONG_MAX

int size,m,n;
ll tree[400000];

void update(int pos, ll x){
    int index = size + pos - 1;
    tree[index] = MAX;


    ll u = std::min(x,tree[index]);

    while(index){
        if(!tree[index]) tree[index] = MAX;
        tree[index] = std::min(u,tree[index]);
        
        index /= 2;
    }
}

ll getMin(int start,int end,int left,int right,int pos){
    if(tree[pos] == 0) return MAX;

    if (left > end || start > right) return MAX;

    
    if (left <= start && end <= right) return tree[pos];

    int mid = (start+end)/2;
    return std::min(getMin(start,mid,left,right,pos*2),getMin(mid+1,end,left,right,pos*2+1));
}

int main(){
    int m, n;
    scanf("%d %d", &n, &m);
    for(size = 1; size < n; size*=2);

    for(int i = 1; i <= n; i++){
        ll num;
        scanf("%lld", &num);
        update(i,num);
    }

    /*
    printf("[ ");
    for(int i = 1; i < size*2; i++){
        printf("%d ", tree[i]);
    }
    printf("]\n");
    */
   
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        printf("%lld\n", getMin(1,size,a,b,1));
    }
    return 0;


}