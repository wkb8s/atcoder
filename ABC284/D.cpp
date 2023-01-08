#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int T, p, q;
    cin >> T;
    for(int i=0; i<T; i++){
        long long T;
        cin >> T;
        for(int j=2; j<sqrt(T); j++){
            if(T % j == 0){
                T /= j;
                if(T % j == 0){
                    p = j;
                    q = T / j;
                } else{
                    q = j;
                    p = sqrt(T);
                }
            }
        }
        cout << p << " " << q << endl;
    }
}