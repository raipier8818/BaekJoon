#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int k,n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        cin >> n;
        if(cin.eof() == true) break;
        arr.resize(n);
        for(int i = 0;i < n; i++)
        {
            cin >> arr[i];
            if(cin.eof() == true) break;    
        } 

        vector<int> lis;
        for(int i = 0; i < n; i++){
            int idx = lower_bound(lis.begin(),lis.end(), arr[i]) - lis.begin();
            if(idx == lis.size()){
                lis.push_back(arr[i]);
            }else{
                lis[idx] = arr[i];
            }
        }

        cout << lis.size() << "\n";        
    }
    

}