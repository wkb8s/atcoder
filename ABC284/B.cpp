#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N, cnt=0;
        cin >> N;
        int A[N];
        for(int j=0; j<N; j++){
            cin >> A[j];
            if(A[j] % 2 != 0){
                cnt ++;
            }
        }
        cout << cnt << endl;
    }
}