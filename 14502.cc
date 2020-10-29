#include <stdio.h>


int origin[8][8];
int arr[8][8];
int n,m;

int dir_x[] = {1,-1,0,0};
int dir_y[] = {0,0,1,-1};


void find(int start_row,int start_col){
    for(int i = 0; i < 4; i++){
        int dx = start_row + dir_x[i];
        int dy = start_col + dir_y[i];

        if(dx >= 0 && dx < n && dy >= 0 && dy <= m){
            if(arr[dx][dy] == 0){
                arr[dx][dy] = 2;
                find(dx,dy);

            }
        }

    }
}


int main(){
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int one = 0; one < n*m; one++){
        int row_one = one/n;
        int column_one = one%n;
        
        if(arr[row_one][column_one] == 1 || arr[row_one][column_one] == 2) continue;

        for(int two = one+1; two < n*m; two++){
            int row_two = two/n;
            int column_two = two%n;
            
            if(arr[row_two][column_two] == 1 || arr[row_two][column_two] == 2) continue;

            for(int three = two+1; three < n*m; three++){
                int row_three = three/n;
                int column_three = three%n;

                if(arr[row_three][column_three] == 1 || arr[row_three][column_three] == 2) continue;
            
                arr[row_one][column_one] = 1;
                arr[row_two][column_two] = 1;
                arr[row_three][column_three] = 1;



            }
        }
    }
}