#include <stdio.h>
#include <string.h>

int n;
char arr[51];

char A = '(';
char B = ')';

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%s",arr);
        //printf("%s\n",arr);
        //printf("%d\n", strlen(arr));

        if(arr[0] == B || arr[strlen(arr)-2] == A) printf("NO\n"); continue;

        int A_count = 0, B_count = 0;
        for(int j = 0; j < strlen(arr)-1; j++){
            if(arr[j] == A) A_count++;
            if(arr[j] == B) B_count++;
        }
        printf("%d %d\n",A_count,B_count);
        if(A_count == B_count) printf("YES\n");
        else printf("NO\n");

    }
}