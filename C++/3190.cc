#include <bits/stdc++.h>

using namespace std;
int n,k,l;
int r,c;

int t;
char d;

int board[100][100];
char rotate_time[10001];

vector<pair<int,int>> pos;

void game(int row, int col, string direction, int time){
    //cout << "// r,c : " << row << " " << col << endl;
    //cout << "// t, b : " << rotate_time[time] << " " << board[row][col] << endl;
    //cout << "// size : " << pos.size() << endl;
    //cout << "-------------------" << endl;

    if(row == n || col == n || row < 0 || col < 0){    
        cout << time << "\n";
        return;
    }

    if(find(pos.begin(),pos.end(),make_pair(row,col)) != pos.end() && time != 0){
        cout << time << "\n";
        return;
    }

    pos.push_back(make_pair(row,col));
    if(pos.size() != 0){
        if(board[row][col] != -1) pos.erase(pos.begin());
    }
    
    board[row][col] = 0;


    if(direction == "right"){
        if(rotate_time[time] == 'L'){
            direction = "up";
        }
        else if(rotate_time[time] == 'D'){
            direction = "down";
        }
    }
    else if(direction == "left"){
        
        if(rotate_time[time] == 'L'){
            direction = "down";
        }
        else if(rotate_time[time] == 'D'){
            direction = "up";
        }
    }
    else if(direction == "up"){
        
        if(rotate_time[time] == 'L'){
            direction = "left";
        }
        else if(rotate_time[time] == 'D'){
            direction = "right";
        }
    }
    else if(direction == "down"){
        
        if(rotate_time[time] == 'L'){
            direction = "right";
        }
        else if(rotate_time[time] == 'D'){
            direction = "left";
        }
    }

    if(direction == "right"){
        game(row,col+1,direction,time+1);
    }
    else if(direction == "left"){
        game(row,col-1,direction,time+1);
    }
    else if(direction == "up"){
        game(row-1,col,direction,time+1);
    }
    else if (direction == "down"){
        game(row+1,col,direction,time+1);
    }

    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;

    for(int i = 0; i < k; ++i){
        cin >> r >> c;
        board[r-1][c-1] = -1;
    }   

    cin >> l;

    for(int i = 0; i < l; ++i){
        cin >> t >> d;
        rotate_time[t] = d;
    }

    pos.push_back(make_pair(0,0));
    game(0,0,"right",0);

}