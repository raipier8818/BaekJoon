#include <bits/stdc++.h>
using namespace std;

long long x,y;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    long long start = 0;
    long long end = x;

    long long z = 100*y/x;
    if(z >= 99) {
        cout << -1;
        return 0;
    }
    long long answer = INT_MAX;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long percentage = 100 * (y + mid) / (x + mid);

        //cout << percentage << endl;

        if(z < percentage) {
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    cout << start;
    
}