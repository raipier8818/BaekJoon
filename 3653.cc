#include <stdio.h>

#define ll long long
int size;
ll arr[400000];

void update(int pos, ll x){
    int index = pos + size - 1;
    arr[index] = x;
    index /= 2;

    while(index){
        ll m;
        if(arr[index*2] > arr[index*2+1]){
            m = arr[index*2];
            if(arr[index*2+1]*2 > m){
                m = arr[index*2+1]*2;
            }
        }
        else{
            m = arr[index*2+1];
            if(arr[index*2]*2 > m){
                m = arr[index*2]*2;
            }
        }
        printf(" %d >> %d \n", index, m);
        arr[index] = m;
        index /= 2;
    }
}



int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n == 0) break;
        
        for (size = 1; size < n; size *= 2);
        for(int i = 1; i <= n; i++){
            int num;
            scanf("%d", &num);
            update(i,num);
        }

        printf("%d\n", arr[1]);

    }
    return 0;
}