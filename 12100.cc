#include <bits/stdc++.h>
using namespace std;

int n;
int arr[20][20][6];

int ans;

void ResetLayer(int layer){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j][layer] = 0;
        }
    }
}


int FindMax(){
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result = max(result, arr[i][j][6]);
        }
    }
    return result;
}


void find(string dir, int layer){
    if(layer > 5){
        ans = max(ans,FindMax());
        return;
    }

    ResetLayer(layer);

    bool c = false;

    if(dir == "left"){
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                bool c = false;
                for(int target = 1; target < n; target++){
                    if(arr[row][col][layer-1] == arr[row][target][layer-1]){
                        arr[row][col][layer] = arr[row][col][layer-1] * 2;
                        arr[row][target][layer] = 0;
                        c = true;
                        break;
                    }
                }

                if(c == false) col--;
            }
        }
    }

    if(dir == "right"){
        for(int row = 0; row < n; row++){
            for(int col = n-1; col >= 0; col--){
                bool c = false;
                for(int target = n-2; target >= 0; target--){
                    if(arr[row][col][layer-1] == arr[row][target][layer-1]){
                        arr[row][col][layer] = arr[row][col][layer-1] * 2;
                        arr[row][target][layer] = 0;
                        break;
                    }
                }

                if(c == false) col--;
            }
        }
    }
    
    c = false;

    if(dir == "up"){
        for(int col = 0; col < n; col++){
            for(int row = 0; row < n; row++){
                bool c = false;
                for(int target = 1; target < n; target++){
                    if(arr[row][col][layer-1] == arr[target][col][layer-1]){
                        arr[row][col][layer] = arr[row][col][layer-1] * 2;
                        arr[target][row][layer] = 0;
                        break;
                    }
                }

                if(c == false) row--;
            }
        }
    }

    c = false;

    if(dir == "down"){
        for(int col = 0; col < n; col++){
            for(int row = 0; row < n; row++){
                bool c = false;
                for(int target = n-1; target >= 0; target--){
                    if(arr[row][col][layer-1] == arr[target][col][layer-1]){
                        arr[row][col][layer] = arr[row][col][layer-1] * 2;
                        arr[target][row][layer] = 0;
                        break;
                    }
                }

                if(c == false) row--;
            }
        }
    }

    find("left", layer+1);
    find("right", layer+1);
    find("up", layer+1);
    find("down", layer+1);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j][0];
        }
    }
    
    int layer = 0;

    find("left", layer+1);
    find("right", layer+1);
    find("up", layer+1);
    find("down", layer+1);

    cout << ans << endl;
}