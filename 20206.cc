#include <bits/stdc++.h>

using namespace std;


double a,b,c;
double x,x_,y,y_;



int main(){

    cin >> a >> b >> c;
    cin >> x >> x_ >> y >> y_;
    
    // y = -(a/b)x - (c/b)

    bool check = false;
    
    if(b!= 0)
    {
        auto l = -1*(a/b)*x - (c/b);
        auto l_ = -1*(a/b)*x_ - (c/b);
    
        if((y < l && l < y_)||(y < l_ && l_ < y_)) check = true;
    }
    if(a != 0)
    {
        auto m = -1*(b/a)*y - (c/a);
        auto m_ = -1*(b/a)*y_ - (c/a);
        if((x < m && m < x_)||(x < m_ && m_ < x_)) check = true;
    }
    

    if(check) cout << "Poor" << endl;
    else cout << "Lucky" << endl;
    
}