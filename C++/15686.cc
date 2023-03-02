#include <bits/stdc++.h>
using namespace std;

int n, m;
int street[51][51];
vector<pair<int,int>> chickens; 
vector<pair<int,int>> houses;

template<typename T>
void print_vector(vector<T>& temp){
    cout << "// ";
    for(T t : temp){
        cout << t << " ";
    } 
    cout << endl;
}

int calculate_chicken_distance(vector<int> selected){
    vector<int> distances;
    distances.resize(houses.size());

    for(int i = 0; i < houses.size(); i++){
        for(int j = 0; j < selected.size(); j++){
            int temp = abs(houses[i].first - chickens[selected[j]].first) + abs(houses[i].second - chickens[selected[j]].second);
            distances[i] = distances[i] == 0 ? temp : min(temp, distances[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i < distances.size(); i++){
        ans += distances[i];
    }
    return ans;
}


int select_chickens(int idx, vector<int> selected){
    if(selected.size() == m){
        // print_vector(selected);
        return calculate_chicken_distance(selected);
    }

    if(idx == chickens.size()){
        return INT_MAX;
    }

    int temp1 = select_chickens(idx+1, selected);
    selected.push_back(idx);
    int temp2 = select_chickens(idx+1, selected);
    return min(temp1, temp2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> street[i][j];
            if(street[i][j] == 1){
                houses.push_back({i,j});
            }
            if(street[i][j] == 2){
                chickens.push_back({i,j});
            }
        }
    }

    vector<int> selected;
    cout << select_chickens(0, selected) << endl;
}   
