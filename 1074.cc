#include<bits/stdc++.h>

using namespace std;

int n,r,c;
int N;

void find(int x, int y, int size, int count){
    //cout << endl;
    
    //cout << x << " " << y << " " << size << " " << count << endl;

    if(size == 1) {
        cout << count << endl;
        return;    
    }

    //cout << 1;
    if(x <= size/2 && y <= size/2) find(x,y,size/2, count);
    
    //cout << 2;
    if(x <= size/2 && y > size/2) find(x,y - size/2,size/2, count + (size/2)*(size/2));
    
    //cout << 3;
    if(x > size/2 && y <= size/2) find(x - size/2,y,size/2, count + 2*(size/2)*(size/2));
    
    //cout << 4;
    if(x > size/2 && y > size/2) find(x - size/2,y - size/2,size/2, count + 3*(size/2)*(size/2));

    return;
}


int main(){
    cin >> n >> r >> c;

    N = 1;    
    for(int i = 0; i < n; i++) {
        N *= 2;
    }
    r++;
    c++;

    find(r,c,N,0);

}