#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> meetings;

bool comp_start(pair<int,int> lhs, pair<int,int> rhs){
    return lhs.first < rhs.first ? 1 : 0; 
}

bool comp_end(pair<int,int> lhs, pair<int,int> rhs){
    return lhs.second < rhs.second ? 1 : 0; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int start,end;
        cin >> start >> end;
        meetings.push_back(make_pair(start,end));
    }

    sort(meetings.begin(), meetings.end(), comp_start);
    sort(meetings.begin(), meetings.end(), comp_end);

    int answer = 0;
    int start = 0;
    int end = 0;

    for(int i = 0; i < meetings.size(); i++){
        if(i == 0){
            answer++;
            start = meetings[0].first;
            end = meetings[0].second;
            continue;
        }

        if(meetings[i].first >= end){
            answer++;
            start = meetings[i].first;
            end = meetings[i].second;
        }
    }

    cout << answer << "\n";
}