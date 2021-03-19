#include <bits/stdc++.h>
using namespace std;

bool check(double a, double b){
    return (a*a-b);
}


int formulaA(double a,double b){
    return ((-a+sqrt(a*a-b)));
}
int formulaB(double a,double b){
    return ((-a-sqrt(a*a-b)));
}


int main(){
    double a,b;
    cin >> a >> b;

    if(check(a,b)){
        if(formulaA(a,b) > formulaB(a,b)) cout << formulaB(a,b) << " " << formulaA(a,b) << endl;
        if(formulaA(a,b) < formulaB(a,b)) cout << formulaA(a,b) << " " << formulaB(a,b) << endl;
    }else
    {
        cout << formulaA(a,b) << endl;
    }
    


}