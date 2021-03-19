#include <bits/stdc++.h>

using namespace std;

int n,m;

int pos_card[10000001];
int neg_card[10000000];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if(c >= 0){
            pos_card[c] = 1;
        }else if (c < 0)
        {
            neg_card[-1*c] = 1;
        }
        
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int f;
        cin >> f;
        if(f >= 0){
            cout << pos_card[f] << " ";
        }else if(f < 0){
            cout << neg_card[-1*f] << " ";
        }
    }
    cout << "\n";

}