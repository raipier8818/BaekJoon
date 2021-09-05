#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> arr[i];
    }


    long long start = 0;
    long long end = 2000000000 * 30;

    long long t;

    while(start <= end){
        long long mid = (start + end) / 2;
        long long children = 0;
        
        for(int i = 0; i < m; i++){
            children += mid / arr[i];
        }

        if(children > n){
            t = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    long long temp = 0;

    for(int i = 0; i < m; i++){
        temp += (t - 1) / arr[i];
        if((t - 1) % arr[i] == 0){
            temp++;
        }

        if(temp == n){
            cout << i + 1 << endl;
            return 0;
        }
    }    
}