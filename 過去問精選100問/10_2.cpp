// 別解: ビット全探索を用いて解く

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int q;
    cin >> q;
    int m[q];
    for(int i=0; i<q; i++){
        cin >> m[i];
    }

    int table[40001];
    for(int bit=0; bit<(1<<n); bit++){
        int sum = 0;
        for(int k=0; k<n; k++){
            if(bit & (1<<k)){
                sum += A[k];
            }
        }
        table[sum] = 1;
    }

    for(int i=0; i<q; i++){
        if(table[m[i]]==1){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}