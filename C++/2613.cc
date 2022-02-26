#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[301];
int dp[301];
vector<int> ans;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> num[i+1];
        dp[i+1] = dp[i] + num[i+1];
    }

    int start = 0;
    int end = INT_MAX;
    int answer = INT_MAX;

    while(start <= end){
        int mid = (start + end) / 2;
        int group_temp = 1;
        int val_temp = 0;
        int idx = 0;

        int i = 0;
        for(; i < n; i++){
            val_temp = dp[i] + num[i+1] - dp[idx];
            if(val_temp > mid){
                // cout << ":: " << mid << " " << val_temp << " " << i << endl;
                idx = i;
                group_temp++;
            }
        }

        if(group_temp > m){
            start = mid + 1;
        }else{
            end = mid - 1;
            answer = min(answer, mid);
        }
        
    }

    int idx = 0;
    int temp = 0;
    int i = 0;
    for(; i < n; i++){
        temp = dp[i] + num[i+1] - dp[idx];
        if(temp > answer){
            ans.push_back(i - idx);
            idx = i;
            temp = 0;
        }
    }

    if(ans.back() != i)
        ans.push_back(i - idx);

    cout << answer << endl;
    for(int temp : ans){
        cout << temp << " ";
    }

}