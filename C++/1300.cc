#include <bits/stdc++.h>
using namespace std;

long long n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;

    int start = 1; int end = k;
    long long result = 0;
    
    while(start <= end){
        long long mid = (start + end)/2;

        long long count = 0;
        for(int i = 1; i <= n; i++){
            count += min(n,mid/i);
        }

        if(count < k){
            start = mid + 1;
        }else{
            result = mid;
            end = mid-1;
        }
    }

    cout << result << endl; 
}