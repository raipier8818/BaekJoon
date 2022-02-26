#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        arr.push_back(num);
    }

    cin >> m;

    int start = 0;
    int end = m;


    int answer = 0;
    while(start <= end){
        int mid = (start + end) / 2;

        int temp = 0;
        int findmax = 0;
        for(int i = 0; i < n; i++){
            temp += min(arr[i], mid);
            findmax = max(findmax, min(arr[i],mid));
        }

        if(temp > m) end = mid - 1;
        else{
            start = mid + 1;
            answer = max(answer, findmax);
        }
    }

    cout << answer;
}