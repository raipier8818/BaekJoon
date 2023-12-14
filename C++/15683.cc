#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cctv[][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0},
};

int solution(int n, int m, vector< vector<char> >& v, int x, int y);

vector< vector<char> > spread(int n, int m, vector< vector<char> > v, int x, int y, int dir){
    vector< vector<char> > temp_v(n, vector<char>(m, '0'));
    copy(v.begin(), v.end(), temp_v.begin());

    int nx = x;
    int ny = y;
    while(true){
        nx += cctv[dir][0];
        ny += cctv[dir][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny] == '6') break;
        if(v[nx][ny] != '0') continue;
        temp_v[nx][ny] = '#';
    }
    return temp_v;   
}

int cctv1(int n, int m, vector< vector<char> > v, int x, int y){
    vector< vector<char> > temp_v;

    int answer = 999999;
    for(int i = 0; i < 4; i++){
        temp_v = spread(n, m, v, x, y, i);
        answer = min(answer, solution(n, m, temp_v, x, y));
    }
    return answer;
}

int cctv2(int n, int m, vector< vector<char> > v, int x, int y){
    vector< vector<char> > temp_v;

    int answer = 999999;
    for(int i = 0; i < 2; i++){
        temp_v = spread(n, m, v, x, y, i);
        temp_v = spread(n, m, temp_v, x, y, i+2);
        answer = min(answer, solution(n, m, temp_v, x, y));
    }
    return answer;
}


int cctv3(int n, int m, vector< vector<char> > v, int x, int y){
    vector< vector<char> > temp_v(n, vector<char>(m, '0'));

    int answer = 999999;
    for(int i = 0; i < 4; i++){
        temp_v = spread(n, m, v, x, y, i);
        temp_v = spread(n, m, temp_v, x, y, (i+1)%4);
        answer = min(answer, solution(n, m, temp_v, x, y));
    }
    return answer;
}

int cctv4(int n, int m, vector< vector<char> > v, int x, int y){
    vector< vector<char> > temp_v(n, vector<char>(m, '0'));

    int answer = 999999;
    for(int i = 0; i < 4; i++){
        temp_v = spread(n, m, v, x, y, i);
        temp_v = spread(n, m, temp_v, x, y, (i+1)%4);
        temp_v = spread(n, m, temp_v, x, y, (i+2)%4);
        answer = min(answer, solution(n, m, temp_v, x, y));
    }
    return answer;
}

int cctv5(int n, int m, vector< vector<char> > v, int x, int y){
    vector< vector<char> > temp_v(n, vector<char>(m, '0'));

    temp_v = spread(n, m, v, x, y, 0);
    temp_v = spread(n, m, temp_v, x, y, 1);
    temp_v = spread(n, m, temp_v, x, y, 2);
    temp_v = spread(n, m, temp_v, x, y, 3);

    return solution(n, m, temp_v, x, y);
}

int solution(int n, int m, vector< vector<char> >& v, int x, int y){
    int answer = 999999;
    y++;
    if(y == m){
        y = 0;
        x++;
    }

    if(x == n){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == '0'){
                    cnt++;
                }
            }
        }

        if(cnt <= 4){
        }

        return min(answer, cnt);
    }

    switch (v[x][y]) {
        case '1':
            answer = min(answer, cctv1(n, m, v, x, y));
            break;
        case '2':
            answer = min(answer, cctv2(n, m, v, x, y));
            break;
        case '3':
            answer = min(answer, cctv3(n, m, v, x, y));
            break;
        case '4':
            answer = min(answer, cctv4(n, m, v, x, y));
            break;
        case '5':
            answer = min(answer, cctv5(n, m, v, x, y));
            break;
        default:
            answer = min(answer, solution(n, m, v, x, y));
            break;
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector< vector<char> > v(n, vector<char>(m, '0'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }


    cout << solution(n, m, v, 0, -1) << endl;

}
