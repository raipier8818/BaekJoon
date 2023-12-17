#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int in_idx[10001];

void postorder(vector<int>& inorder, vector<int>& preorder, int in_s, int in_e, int pre_s, int pre_e){
    if(pre_e < pre_s) return;
    int root = preorder[pre_s];
    // cout << " << " << post_e << " " << post_s << endl;

    int in_m = in_idx[root];
    // while(inorder[in_m] != root && in_m < in_e) in_m++;

    // left ~ root ~ right
    // inorder (ln_s ~ ln_m-1) ~ root(ln_m) ~ (ln_m+1 ~ ln_e)
    // postorder (post_s ~ post_s+ln_m-ln_s) ~ (post_s+ln_m-ln_s+1 ~ post_e-1) ~ root(post_e) 
    int s = in_m - in_s;

    if(in_m != in_s){    
        postorder(inorder, preorder, in_s, in_m-1, pre_s+1, pre_s+s);
    }
    // cout << "DEBUG" << endl;
    if(in_m != in_e){
        postorder(inorder, preorder, in_m+1, in_e, pre_s+s+1, pre_e);
    }
    cout << root << " ";
}

// 1 2 3
// 3 2 1

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int n;  
        cin >> n;

        vector<int> inorder(n, 0);
        vector<int> preorder(n, 0);
        for(int i = 0; i < n; i++){
            cin >> preorder[i];
        }
        for(int i = 0; i < n; i++){
            cin >> inorder[i];
            in_idx[inorder[i]] = i;
        }
        postorder(inorder, preorder, 0, n-1, 0, n-1);
        cout << "\n";
    }    

}
