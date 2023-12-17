#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> slice_paper(int n, vector< vector<int> >& paper, int x, int y){
    vector<int> answer(3,0);
    // cout << n << endl;
    int temp = paper[x][y];
    for(int i = 0; i < n*n; i++){
        if(paper[i/n + x][i%n + y] != temp){
            for(int r = x; r < x + n; r += n/3){
                for(int c = y; c < y + n; c += n/3){
                    vector<int> part_answer = slice_paper(n/3, paper, r, c);                    
                    answer[0] += part_answer[0];
                    answer[1] += part_answer[1];
                    answer[2] += part_answer[2];
                }
            }
            return answer;
        }
    }

    answer[temp+1]++;
    // cout << answer[0] << answer[1] << answer[2] << endl;
    return answer;
}

vector<int> solution(int n, vector< vector<int> >& paper){
    return slice_paper(n, paper, 0, 0);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector< vector<int> > paper(n,vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }

    vector<int> answer = solution(n, paper);
    cout << answer[0] << endl;
    cout << answer[1] << endl;
    cout << answer[2] << endl;
}
