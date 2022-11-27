#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll mod = 1000000007;

/*
페르마의 소정리
a != kp (k는 정수, p는 소수)
a^(p-1) % p = 1

A = n!
B = k!(n-k)!
p = 1000000007
AB^(-1) % p = ?
B^(p-1) % p = 1
B^(p-2)*B % p = 1
B^(p-2) % p = B^(-1)
AB^(-1) % p = AB^(p-2) % p
= (A%p)(B^(p-2)%p)%p

*/

ll factorial(int n){
    if(n <= 1) return 1;
    return n * factorial(n-1) % mod;
}

ll powInt(int a, int k){
    if(a == 1) return 1;
    if(k == 1) return a;
    if(k == 0) return 1;

    ll temp = powInt(a, k / 2) % mod;
    if(k % 2 == 0){
        return (temp * temp) % mod;
    }else{
        return (((temp * temp) % mod) * a) % mod;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cout << (factorial(n)%mod)*(powInt(factorial(k)*factorial(n-k)%mod, mod-2)%mod)%mod << endl;   
}
