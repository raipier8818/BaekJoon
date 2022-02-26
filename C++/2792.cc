#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int end = 0;
    for(int i = 0; i < m; i++){
        int num; cin >> num;
        arr.push_back(num);
        
        end = max(end, arr[i]);
    }
    
    int answer = INT_MAX;
    int start = 1;
    while(start <= end){
        int mid = (start + end) / 2;
        int temp = 0;
        
        if(mid != 0){

            for(int i = 0; i < m; i++){
                int div = arr[i] / mid;
                int rem = arr[i] % mid;

                if(!rem) temp += div;
                else temp += div + 1;
            }

        }

        if(temp > n){
            start = mid + 1;
        }else{
            end = mid - 1;
            answer = min(answer, mid);
        }
    }

    cout << answer << "\n";

}