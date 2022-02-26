#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];

bool comp(pair<int,int> l, pair<int,int> r){
    return (l.first < r.first ? true : false) ;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int count = 0;

    vector<pair<int,int>> v;
    n--;
    while(n--){
        int a,b;
        cin >> a >> b;
        if(b < a)
            v.push_back(make_pair(b,a));
        else
            v.push_back(make_pair(a,b));
    }

    sort(v.begin(),v.end(), comp);

    for(pair<int,int> temp : v){
        int a = temp.first;
        int b = temp.second;

        cout << a << " " << b << endl;

        if(arr[a] == 0 && arr[b] == 0){
            count++;
            arr[a] = count;
            arr[b] = count;

            cout << "two zero : " << count << endl;
        }
        else if(arr[a] == 0){
            arr[a] = arr[b];

            cout << "a zero : " << count << endl;
        }else if(arr[b] == 0){
            arr[b] = arr[a];

            cout << "b zero : " << count << endl;
        }
    }

    cout << count;
}