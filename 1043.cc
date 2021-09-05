#include <bits/stdc++.h>
using namespace std;

int n,m;
int t;
int t_arr[51];
int p_arr[51][51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> t;
    for(int i = 0; i < t; i++){
        int num; cin >> num;
        t_arr[num] = 1;
    }

    int answer = 0;
    for(int i = 0; i < m; i++){
        int p_num; cin >> p_num;
        bool check = false;
        for(int j = 0; j < p_num; j++){
            cin >> p_arr[i][j];
            if(t_arr[p_arr[i][j]] == 1) check = true;
        }
        
        if(!check) continue;
        for(int j = 0; j < p_num; j++){
            t_arr[p_arr[i][j]] = 1;
        }
    }

    for(int i = 0; i < m; i++){
        bool check = false;
        for(int j = 0; j < n && p_arr[i][j] != 0; j++){
            if(t_arr[p_arr[i][j]] == 1){
                check = true;
                break;
            }
        }

        if(!check){
            answer++;
        }
    }
    
    cout << answer;
}