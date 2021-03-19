#include <bits/stdc++.h>

using namespace std;
int n;
char arr[100][100];

vector<vector<char>> s;


vector<pair<char,int>> v;

bool check(int x, int y, int size){
    char init = arr[x][y];


    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(arr[i][j] != init) return false; 
        }
    }
    return true;
}


void quad(int x, int y, int size){
    if(size == 0) return;

    if(check(x,y,size)){
        char c = arr[x][y] == '1' ? '1' : '0';
        //cout << "push back : " << c << endl;
        v.push_back({c,size});
        s[size].push_back(c);
        return;
    }

    //cout << "//" << x << "//" << y << "//" << size << endl;


    v.push_back({'(',size});

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            quad(x + i*(size/2), y + j*(size/2), size/2);
        }
    }
    v.push_back({')',size});
}


int main(){
    cin >> n;

    s.resize(1000);
    for(int i = 0; i < n; i++){
        char row[100];
        cin >> row;
        for(int j = 0; j < n; j++){
            arr[i][j] = row[j];
        }
    }
    quad(0,0,n);

    for(int i = 0; i < v.size(); i++){
        cout << v[i].first;
    }


}