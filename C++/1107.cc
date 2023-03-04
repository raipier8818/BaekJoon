#include <bits/stdc++.h>
using namespace std;

int calculate(int num, vector<int>& workings){
    if(num == 0) return workings[num] == 0 ? 1 : -1;

    int length = 0;
    while(num != 0){
        if(workings[num%10] == -1) return -1;
        num /= 10;
        length++;
    }
    return length;
}

int solution(int n, int m, vector<int>& buttons){
    if(n == 100) return 0;

    vector<int> workings;
    workings.resize(10);
    for(int btn : buttons){
        workings[btn] = -1;
    }    
    if(calculate(n, workings) != -1) return min(calculate(n, workings), abs(n-100));

    int ans = INT_MAX;

    for(int i = 0; i <= 10000000; i++){
        int temp = calculate(i, workings);
        if(temp == -1){
            ans = min(ans, abs(n - 100));
        }else{
            ans = min(ans, temp + abs(n - i));
        }
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    vector<int> buttons;

    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;

        buttons.push_back(temp);
    }

    cout << solution(n,m,buttons) << endl;
}   
