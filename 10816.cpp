#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];

int lower(int*arr, int target, int size){
    int mid, start, end;
    start = 0, end = size-1;

    while (end > start){
        mid = (start+end)/2;
        if (arr[mid] >= target){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    
    }
    return end;
}

int upper(int*arr, int target, int size){
    int mid, start, end;
    start = 0, end = size-1;

    while (end > start){
        mid = (start+end)/2;
        if (arr[mid] > target){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    
    }
    return end;
}

int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int num;
        cin >> num;
        cout << upper(arr, num, n) - lower(arr, num, n);
    }


}