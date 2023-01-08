#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int G[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            G[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        int u, k;
        cin >> u >> k;
        for(int j=0; j<k; j++){
            int v;
            cin >> v;
            G[u-1][v-1] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << G[i][j];
            if(j != n-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}