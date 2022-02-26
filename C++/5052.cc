#include <bits/stdc++.h>
using namespace std;

int t,n;
bool check = false;
vector<string> book;
typedef struct _node{
    char val;
    bool final = false;
    struct _node* child[10];
}node;

node* init(){
    node* newNode = new node();
    for(int i = 0; i < 10; i++){
        newNode->child[i] = NULL;
    }
    return newNode;
}

void insert(node* root, string val){
    int idx = 0;
    node* temp = root;
    //cout << val << endl;


    while(idx != val.size()){
        char i = val[idx];
        if(temp->final == true){
            check = true;
            break;
        }


        if(temp->child[i-48] == NULL){
            //cout << "insert " << val[idx] << endl;
            
            node* newNode = init();
            newNode->val = i;
            temp->child[i-48] = newNode;
            temp = temp->child[i-48];
            idx++;
        }else{
            //cout << "pass " << val[idx] << endl;

            temp = temp->child[i-48];
            idx++;
        }
    }  

    if(temp->final == true){
        check = true;
        return;
    }

    temp->final = true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        node* root = init();
        book.clear();
        check = false;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            book.push_back(s);
        }

        sort(book.begin(), book.end());

        for(string temp : book){
            insert(root, temp);
            //cout << check << endl;
            if(check) break;
        }

        if(check) cout << "NO\n";
        else cout << "YES\n"; 
    }
}