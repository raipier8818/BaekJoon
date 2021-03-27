#include <bits/stdc++.h>
using namespace std;

int n;
int arr[500001];
long long answer = 0;


void ms(int start, int end){
    if(start >= end) return;

    int mid = (start + end)/2;
    
    int left = start;
    int right = mid + 1;

    ms(start,mid);
    ms(mid+1,end);

    vector<int> temp;
    while(left <= mid && right <= end){
        if(arr[left] > arr[right]){
            answer += mid + 1 - left;
            temp.push_back(arr[right++]);
        }else{
            temp.push_back(arr[left++]);
        }
    }

    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= end){
        temp.push_back(arr[right++]);
    }

    for(int i = 0; i < temp.size(); i++){
        arr[start + i] = temp[i];
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ms(0,n-1);
    cout << answer << "\n";
}