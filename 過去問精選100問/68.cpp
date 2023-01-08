#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << ":";
    int N = n;
    for(int i=2; i<sqrt(n); i++){
        while(N%i == 0){
            cout << " " << i;
            N /= i;
        }
    }
    if(N != 1){
        cout << " " << N;
    }
    cout << endl;
}       