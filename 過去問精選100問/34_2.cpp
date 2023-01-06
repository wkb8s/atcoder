#include <bits/stdc++.h>
using namespace std;

int fib(int n, int *m){
    if(n == 0 || n == 1){
        return 1;
    } else if(m[n] == -1){
        m[n] = fib(n-1, m) + fib(n-2, m);
        return m[n];
    } else {
        return m[n];
    }
}

int main() {
    int n;
    cin >> n;
    int m[n+1];
    for(int i=0; i<n+1; i++){
        m[i] = -1;
    }
    cout << fib(n, m) << endl;
}