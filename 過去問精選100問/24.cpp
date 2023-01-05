#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int G[n][n];
    int u, k;
    for(int i=0; i<n; i++){
        cin >> u >> k;
        u--;
        for(int j=0; j<k; j++){
            int v;
            cin >> v;
            v--;
            G[u][v]++;
        }
    }
    // unsolved
}