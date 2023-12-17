#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void preorder(vector<int>& inorder, vector<int>& postorder, int in_s, int in_e, int post_s, int post_e){
    int root = postorder[post_e];
    cout << root << " ";
    // cout << " << " << post_e << " " << post_s << endl;
    if(post_e == post_s) return;

    int in_m = in_s;
    while(inorder[in_m] != root && in_m < in_e) in_m++;

    // left ~ root ~ right
    // inorder (ln_s ~ ln_m-1) ~ root(ln_m) ~ (ln_m+1 ~ ln_e)
    // postorder (post_s ~ post_s+ln_m-ln_s) ~ (post_s+ln_m-ln_s+1 ~ post_e-1) ~ root(post_e) 

    if(in_m != in_s){    
        int s = in_m - in_s;
        preorder(inorder, postorder, in_s, in_s+s-1, post_s, post_s+s-1);
    }
    // cout << "DEBUG" << endl;
    if(in_m != in_e){
        int s = in_e-in_m;
        preorder(inorder, postorder, in_e-s+1, in_e, post_e-s, post_e-1);
    }
}

// 1 2 3
// 3 2 1

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> inorder(n, 0);
    vector<int> postorder(n, 0);
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }
    for(int i = 0; i < n; i++){
        cin >> postorder[i];
    }
    preorder(inorder, postorder, 0, n-1, 0, n-1);
}
