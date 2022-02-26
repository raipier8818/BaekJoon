#include <bits/stdc++.h>
using namespace std;

int n, score;

vector <pair<int,int>> assingment;

void DoAssignment(){
    if(assingment.empty()) return;
    
    if(assingment.back().second > 0) assingment.back().second -= 1;
    if(assingment.back().second == 0) {
        score += assingment.back().first;
        assingment.pop_back();
    }

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    score = 0;
    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a;
        if(a == 0) {
            DoAssignment();
            continue;
        };
        cin >> b >> c;
        assingment.push_back(make_pair(b,c));
        DoAssignment();
    }

    cout << score << endl;
}