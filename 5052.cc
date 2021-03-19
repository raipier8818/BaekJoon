#include <bits/stdc++.h>
using namespace std;

int t,n;
vector<string> book;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        book.clear();

        cin >> n;
        while(n--){
            string p;
            cin >> p;
            book.push_back(p);  
        }
        
        sort(book.begin(),book.end());

        bool check = true;
        for(int i = 0; i < book.size() - 1; i++){
            for(int j = i+1; j < book.size(); j++){
                if(book[j].find(book[i],0) != string::npos){
                    //cout << book[i] << endl;
                    //cout << book[j] << endl;

                    check = false;
                    break;
                }
            }
            if(!check) break;
        }

        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
}