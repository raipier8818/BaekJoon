#include <bits/stdc++.h>

using namespace std;
int h,x;
int INF = 1000000007;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> x;
    
    long long sum = 0;
    long long temp = x;

    for(int i = 1; i <= h; i++){
        int num;
        cin >> num;
        sum += num*temp%INF;
        temp *= x;
        temp %= INF;
        sum %= INF;

    }
    
    cout << sum << endl;
}