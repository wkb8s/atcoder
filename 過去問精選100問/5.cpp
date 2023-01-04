#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y, ans=1000000000;
    cin >> A >> B >> C >> X >> Y;
    for(int i=0; i<=max(X,Y); i++){
        if(A*max(0,X-i) + B*max(0,Y-i) + 2*C*i < ans){
            ans = A*max(0,X-i) + B*max(0,Y-i) + 2*C*i;
        }
    }
    cout << ans <<endl;
}