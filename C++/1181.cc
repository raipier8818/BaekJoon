#include <bits/stdc++.h>
using namespace std;

struct Trie{
    char val;
    Trie* next[26];
    bool last = false;
};

Trie* initTrie(){
    Trie *trie = new Trie();
    trie->val = 0;
    for(int i = 0; i < 26; i++){
        trie->next[i] = NULL;
    }
    trie->last = false;    
    return trie;
}

void insertTrie(Trie* t, string val, int idx){
    
    if(t->next[val[idx] - 'a'] == NULL){
        Trie *temp = initTrie();
        t->next[val[idx] - 'a'] = temp;
        temp->val = val[idx];
        if(val.size() == idx + 1){
            temp->last = true;
            return;
        }else{
            temp->last = false;
            insertTrie(temp, val, idx + 1);
        }
    }else{
        Trie* temp = t->next[val[idx] - 'a'];
        if(val.size() == idx + 1){
            temp->last = true;
        }else{
            insertTrie(temp, val, idx + 1);
        }
    }
}

void printTrie(Trie* t, string val){
    if(t->last){
        cout << val + t->val << endl;
    }

    for(int i = 0; i < 26; i++){
        if(t->next[i] != NULL){
            printTrie(t->next[i], val + t->val);
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    Trie *trie = initTrie();

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        insertTrie(trie, word, 0);
    }

    printTrie(trie, "");
}