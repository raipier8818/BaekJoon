#include <bits/stdc++.h>
using namespace std;

int n,h;
int var;

vector<double> up;
vector<double> down;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    for(int i = 0;i < n; i++){
        int num;
        cin >> num;
        
        if(i % 2 == 0){
            down.push_back(num);
        }else{
            up.push_back(num);
        }
    }

    sort(up.begin(),up.end());
    sort(down.begin(),down.end());


    int answer = INT_MAX;
    int count = 1;

    for(int i = 1; i <= h; i++){
        int temp = down.size() - (lower_bound(down.begin(),down.end(),i) - down.begin());
        temp += up.size() - (upper_bound(up.begin(), up.end(), h - i) - up.begin());
    
        if(answer == temp) count++;
        else if(answer > temp){
            count = 1;
            answer = temp;
        }
    
    }

    cout << answer << " " << count << "\n";


}