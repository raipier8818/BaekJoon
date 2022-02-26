#include <bits/stdc++.h>
int INF = -1*INT_MAX;

int n;
std::vector <int> v;

int main(){
    std::cin >> n;
    
    v.push_back(INF);

    for(int i = 0; i < n; i++){
        int putNum;
        std::cin >> putNum;

        if(v.at(v.size()-1) < putNum){
            v.push_back(putNum);
        }else{
            auto it = std::lower_bound(v.begin(),v.end(),putNum);
            *it = putNum;
        }
    }

    std::cout << v.size()-1 << "\n";
}