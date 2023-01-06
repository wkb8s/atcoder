#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int F[n+1];
    F[0] = 1;
    F[1] = 1;
    for(int i=2; i<n+1; i++){
        F[i] = F[i-1] + F[i-2];
    }
    cout << F[n] << endl;
}

// 計算量が大きすぎる
// #include <bits/stdc++.h>
// using namespace std;

// int fib(int n){
//     if(n == 0 || n == 1){
//         return 1;
//     } else {
//         return fib(n-1) + fib(n-2);
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     cout << fib(n) << endl;
// }