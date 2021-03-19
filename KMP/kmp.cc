#include <bits/stdc++.h>
using namespace std;

int skip[1000]; 

int kmp(string pattern, string txt){
    int pt = 1;
    int pp = 0;

    while(pt < pattern.size()){
        if(pattern[pt] == pattern[pp]){
            skip[pt] = skip[pt-1] + 1;
            pt++;
            pp++;
        }else{
            skip[pt++] = 0;
            pp = 0;
        }
    }


    for(int i = 0; i < pattern.size(); i++){
        cout << " " << skip[i];
    }
    cout << endl;

    pt = pp = 0;

    while(pt < txt.size() && pp < pattern.size()){
        cout << "//" << pt << " " << pp << endl;

        if(txt[pt] == pattern[pp]){
            pt++; pp++;
        }else if(pp == 0){
            pt++;
        }else{
            pp = skip[pp-1];
        }
    }

    if(pp == pattern.size()) return pt - pp;

    return -1;

}
 

int main(){
    string text, pattern;
    cin >> text;
    cin >> pattern;

    cout << kmp(pattern,text);
}