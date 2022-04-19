#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n;

struct compare {
    bool operator()(const string& a, const string& b) const{
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
};

int main(){
    cin >> n;
    set<string, compare> words;

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        
        words.insert(word);
    }

    for(string temp : words){
        cout << temp << endl;
    }
}