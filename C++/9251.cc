#include <bits/stdc++.h>
//and 9252


using namespace std;

string A;
string B;

string result = "";

int dp[1001][1001];


int main(){

    cin >> A;
    cin >> B;    

    for(int i = 1; i <= B.size(); ++i){
        for(int j = 1; j <= A.size(); ++j){
            if(A[j-1] == B[i-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;   
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int j = A.size();
    int i = B.size();

    while(i > 0){
        while (j > 0)
        {
            //cout << i <<  " " << j << endl;
            if(dp[i][j] != dp[i][j-1] && dp[i][j] != dp[i-1][j-1]){
                if(dp[i-1][j] == dp[i][j]){
                    i -= 1;
                    continue;
                }
                result = B[i-1] + result;
                i -= 1;
                j -= 1;
            }
            else j -= 1;
            
        }
        if(j == 0) break;
    }

    cout << dp[B.size()][A.size()] << endl;
    cout << result << endl;

}