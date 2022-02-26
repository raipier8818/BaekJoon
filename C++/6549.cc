#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long>arr;

long long findArea(long long start, long long end){
    if(start > end) return 0;
    if(start == end) return arr[start];
    
    long long mid = (start + end) / 2;
    long long leftArea = findArea(start, mid - 1);
    long long rightArea = findArea(mid + 1, end);

    long long left = mid - 1;
    long long right = mid + 1;

    long long area = arr[mid];

    long long horizontal = 2;
    long long min_height = arr[mid];

    long long temp;
    while (left >= start && right <= end)
    {
        if(arr[left] > arr[right]){
            min_height = min(min_height,arr[left]);
            temp = min_height * (horizontal);
            left--;
            horizontal++;
        }else{
            min_height = min(min_height,arr[right]);
            temp = min_height * (horizontal);
            right++;
            horizontal++;
        }

        if(area < temp) area = temp;
    }

    while(left >= start){
        min_height = min(min_height,arr[left]);
        temp = min_height * (horizontal);
        left--;
        horizontal++;
        if(area < temp) area = temp;
    }

    while (right <= end)
    {
        min_height = min(min_height,arr[right]);
        temp = min_height * (horizontal);
        right++;
        horizontal++;
        if(area < temp) area = temp;
    }
    
    
    if(area < leftArea) area = leftArea;
    if(area < rightArea) area = rightArea;

    return area;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> n;
        if(n == 0) break;
        arr.clear();
        arr.resize(n);
        
        for(long long i = 0;i < n; i++){
            cin >> arr[i];
        }

        cout << findArea(0,n-1) << "\n";
    }
    

}