#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int pow(int x, int y){
    int result = 1;
    while(y--){
        result *= x;
    }
    return result;
}

bool cubes_empty(vector< pair< int,int > > &cubes){
    int check = 0;
    for(auto i : cubes){
        check += i.second;
    }
    return check == 0;
}

int solution(vector< pair<int,int> > &cubes, int l, int w, int h){
    if(!l || !w || !h) return 0;
    if(cubes_empty(cubes) && l + w + h > 0) return -1;
    // cout << "<< " << l << " " << w << " " << h << " " << endl;

    int min_s = min(min(l,w),h);
    auto cube_iter = cubes.rbegin();
    for(; cube_iter != cubes.rend(); ++cube_iter){
        if(cube_iter->second > 0){
            if(pow(2, cube_iter->first) <= min_s){
                // cout << " size : " << pow(2, cube_iter->first) << endl;
                break;
            }
        }
    }

    if(cube_iter == cubes.rend()) return -1;

    int cube_s = pow(2,cube_iter->first);
    cube_iter->second--;

    if(l == cube_s && w == cube_s && h == cube_s) return 1;

    // cout << ">> " << cube_s << endl;
    int b = solution(cubes, cube_s, w-cube_s, cube_s);
    int a = solution(cubes, l-cube_s, w, cube_s);
    int c = solution(cubes, l, w, h-cube_s);
    if(a < 0 || b < 0 || c < 0) return -1;
    return a + b + c + 1; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l, w, h;
    int n;
    cin >> l >> w >> h;
    cin >> n;
    vector< pair<int,int> > cubes;
    for(int i = 0; i < n; i++){
        int s,c; cin >> s >> c;
        cubes.push_back(make_pair(s, c));
    }
    sort(cubes.begin(), cubes.end());
    
    cout << solution(cubes, l, w, h) << endl;
}
