#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector< vector<int> > move_left(int n, vector< vector<int> >& board){
    vector< vector<int> > temp_board(n, vector<int>(n,0));

    for(int i = 0; i < n; i++){
        int temp_idx = 0;
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0){
                continue;
            }else if(temp_board[i][temp_idx] == 0){
                temp_board[i][temp_idx] = board[i][j];
            }else{
                if(temp_board[i][temp_idx] == board[i][j]){
                    temp_board[i][temp_idx] *= 2;
                    temp_idx++;
                }else{
                    temp_idx++;
                    temp_board[i][temp_idx] = board[i][j];
                }
            }
        }
    }

    return temp_board;
}

vector< vector<int> > move_right(int n, vector< vector<int> >& board){
    vector< vector<int> > temp_board(n, vector<int>(n,0));


    for(int i = 0; i < n; i++){
        int temp_idx = n-1;
        for(int j = n-1; j >= 0; j--){
            if(board[i][j] == 0){
                continue;
            }else if(temp_board[i][temp_idx] == 0){
                temp_board[i][temp_idx] = board[i][j];
            }else{
                if(temp_board[i][temp_idx] == board[i][j]){
                    temp_board[i][temp_idx] *= 2;
                    temp_idx--;
                }else{
                    temp_idx--;
                    temp_board[i][temp_idx] = board[i][j];
                }
            }
        }
    }

    return temp_board;
}

vector< vector<int> > move_up(int n, vector< vector<int> >& board){
    vector< vector<int> > temp_board(n, vector<int>(n,0));


    for(int j = 0; j < n; j++){
        int temp_idx = 0;
        for(int i = 0; i < n; i++){
            if(board[i][j] == 0){
                continue;
            }else if(temp_board[temp_idx][j] == 0){
                temp_board[temp_idx][j] = board[i][j];
            }else{
                if(temp_board[temp_idx][j] == board[i][j]){
                    temp_board[temp_idx][j] *= 2;
                    temp_idx++;
                }else{
                    temp_idx++;
                    temp_board[temp_idx][j] = board[i][j];
                }
            }
        }
    }

    return temp_board;
}

vector< vector<int> > move_down(int n, vector< vector<int> >& board){
    vector< vector<int> > temp_board(n, vector<int>(n,0));


    for(int j = 0; j < n; j++){
        int temp_idx = n-1;
        for(int i = n-1; i >= 0; i--){
            if(board[i][j] == 0){
                continue;
            }else if(temp_board[temp_idx][j] == 0){
                temp_board[temp_idx][j] = board[i][j];
            }else{
                if(temp_board[temp_idx][j] == board[i][j]){
                    temp_board[temp_idx][j] *= 2;
                    temp_idx--;
                }else{
                    temp_idx--;
                    temp_board[temp_idx][j] = board[i][j];
                }
            }
        }
    }

    return temp_board;
}

void print_board(int n, vector< vector<int> >& board){
    cout << "----" << n << "----" << endl;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool check_same(int n, vector< vector<int> >& A, vector< vector<int> >& B){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}

int get_high_num(int n, vector< vector<int> >& board){
    int max_num = 0;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            max_num = max(max_num, board[i][j]);
        }
    }
    return max_num;
}

int solution(int n, vector< vector<int> > board, int count){
    if(n == 1){
        return get_high_num(n, board);
    }

    if(count == 5){
        return get_high_num(n, board);
    }
    int answer = 0;

    vector< vector<int> > temp;
    temp = move_left(n, board);
    if(!check_same(n, board, temp)) answer = max(answer, solution(n, temp, count+1));

    temp = move_right(n, board);
    if(!check_same(n, board, temp)) answer = max(answer, solution(n, temp, count+1));

    temp = move_up(n, board);
    if(!check_same(n, board, temp)) answer = max(answer, solution(n, temp, count+1));

    temp = move_down(n, board);
    if(!check_same(n, board, temp)) answer = max(answer, solution(n, temp, count+1));

    return answer;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector< vector<int> > board(n, vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    cout << solution(n, board, 0) << endl;
}
