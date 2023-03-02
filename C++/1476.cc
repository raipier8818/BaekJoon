    #include <bits/stdc++.h>
using namespace std;

int e,s,m;

bool check_year(int temp_e, int temp_s, int temp_m){
    return (e == temp_e) && (s == temp_s) && (m == temp_m);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> e >> s >> m;

    int year = 1;
    int temp_e = 1, temp_s = 1, temp_m = 1;

    while(!(check_year(temp_e, temp_s, temp_m))){
        year++;
        temp_e++;
        temp_s++;
        temp_m++;

        if(temp_e > 15) temp_e = 1;
        if(temp_s > 28) temp_s = 1;
        if(temp_m > 19) temp_m = 1;
    }

    cout << year << endl;
}   
