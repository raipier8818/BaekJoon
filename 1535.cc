#include <bits/stdc++.h>
int n;
int arr[20][2];

int visit[20];
int minNum = 0;

using namespace std;

int check(){
    for(int i = 0; i < n; i++){
        if(visit[i] == 0) return 0;
    }
    return 1;
}


void update(int health, int happiness, int start){

    //cout << "----" << "\n";

    if(health <= 0){
        return;
    }

    //cout << "----" << "\n";
    
    //cout << happiness << "// \n";
    minNum = max(minNum, happiness);
        
    
    
    //cout << "----" << "\n";

    
    //cout << "<" << health << "," << happiness << ">" << "\n";
    //cout << "<<" << minNum << "\n";

    for(int i = 0; i < n; i++){
        if(i >= start && visit[i] == 0){
            visit[i] = 1;
            update(health - arr[i][0], happiness + arr[i][1],i);
            visit[i] = 0;
        }
    }


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[i][0] = num;
    }

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[i][1] = num;
    }

    update(100,0,0);

    cout << minNum << "\n";
}