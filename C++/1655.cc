#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> left, right;
    int mid = 99999;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;

        if(temp > mid){
            right.push(-temp);
            
            if(right.size() > left.size()){
                left.push(-right.top());
                right.pop();
            }
        }else{
            left.push(temp);

            if(left.size() > right.size() + 1){
                right.push(-left.top());
                left.pop();
            }
        }
        mid = left.top();
        cout << "" <<  mid << "\n";
    }
}
