// 部分和問題として解く

#include <bits/stdc++.h>
using namespace std;

int n;
int A[20];

int solve(int i, int m){
    if(m == 0){
        return 1;
    } else if (i == n){
        return 0;
    } else {
        return solve(i+1, m-A[i]) || solve(i+1, m);
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int q;
    cin >> q;
    int m[q];
    for(int i=0; i<q; i++){
        cin >> m[i];
    }

    for(int i=0; i<q; i++){
        if(solve(0, m[i])){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}