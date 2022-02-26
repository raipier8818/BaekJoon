#include <bits/stdc++.h>
using namespace std;

typedef struct _node{
    int val;
    edge parent;
    edge left;
    edge right;
}node;

typedef struct _edge{
    int weight;
    node* next;
}edge;

bool compare(edge lv, edge rv){
    return lv.weight > rv.weight ? false : true;
}

int n, a, b, c;
vector<node> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        
    }
}