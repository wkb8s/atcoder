#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, cnt=0;
    cin >> n;
    int S[n];
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
    cin >> q;
    int T[q];
    for(int i=0; i<q; i++){
        cin >> T[i];
    }

    for(int i=0; i<q; i++){
        int l=0, r=n-1;
        while(l<=r){
            int c = (l+r)/2;
            if(T[i] < S[c]){
                r = c-1;
            } else if(T[i] > S[c]){
                l = c+1;
            } else{
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}