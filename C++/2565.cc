#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr1;
vector<int> arr2;

int main(){
    cin >> n;
    arr1.resize(1000, -1);
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        arr1[a] = b;
    }

    for(int i = 0; i < 1000; i++){
        if(arr1[i] != -1){
            arr2.push_back(arr1[i]);
        }
    }

    vector<int> temp;
    for(int i = 0; i < arr2.size(); i++){
        int t = lower_bound(temp.begin(), temp.end(), arr2[i]) - temp.begin();
        if(t == temp.size()){
            temp.push_back(arr2[i]);
        }else{
            temp[t] = arr2[i];
        }
    }

    cout << arr2.size() - temp.size() << endl;
}