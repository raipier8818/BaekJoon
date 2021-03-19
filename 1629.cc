#include <iostream>
using namespace std;
#define ll long long

ll a,b,c;

ll f(ll n){
    if(n == 0) return 1;
    if(n == 1) return a%c;

    ll temp = f(n/2)%c;

    return n % 2 == 0 ? temp*temp%c : (temp*temp%c)*a%c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    cout << f(b) << "\n";
    
}