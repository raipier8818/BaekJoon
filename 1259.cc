#include <iostream>
#include <string>

using namespace std;

bool pelinrome(string A, int start, int end) {
    if (start >= end - 1) return true;

    return (A[start] == A[end - 1]) && pelinrome(A, start + 1, end - 1);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        string A;
        cin >> A;
        
        if (!A.compare("0")) break;

        if (pelinrome(A, 0, A.size())) {
            cout << "yes" << endl;
        }
        
        else {
            cout << "no" << endl;
        }
    }
}