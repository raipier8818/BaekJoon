#include <bits/stdc++.h>
using namespace std;

int n;
char arr[100][100];
char arrRG[100][100];
int v[100][100];
int vRG[100][100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int area;
bool check;

void find(int r, int c, char a){
    if(r < 0 || r >= n || c < 0 || c >= n) return;
    if(v[r][c] != 0) return;
    if(arr[r][c] != a) return;
    v[r][c] = area;
    check = true;
    for(int i = 0; i < 4; i++){
        find(r + dx[i], c + dy[i],a);
    }        
}

void findRG(int r, int c, char a){
    if(r < 0 || r >= n || c < 0 || c >= n) return;
    if(vRG[r][c] != 0) return;
    if(arrRG[r][c] != a) return;
    vRG[r][c] = area;
    check = true;
    for(int i = 0; i < 4; i++){
        find(r + dx[i], c + dy[i],a);
    }        
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;

        for(int j = 0; j < row.size(); j++){
            arr[i][j] = row[j];
            arrRG[i][j] = row[j];
            if(arr[i][j] == 'G') arrRG[i][j] = 'R';
        }
    }

    area = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            check = false;
            if(arr[i][j] == 'R') find(i,j,'R');
            if(arr[i][j] == 'G') find(i,j,'G');
            if(arr[i][j] == 'B') find(i,j,'B');

            if(check == true) area++;
        }
    }

    cout << area << " ";
    
    area = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            check = false;
            if(arrRG[i][j] == 'R') findRG(i,j,'R');
            if(arrRG[i][j] == 'G') findRG(i,j,'G');
            if(arrRG[i][j] == 'B') findRG(i,j,'B');

            if(check == true) area++;
        }
    }

    cout << area << endl;



}