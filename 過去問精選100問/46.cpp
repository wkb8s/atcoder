#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n+1], m[n+1][n+1];
    for(int i=0; i<n; i++){
        cin >> p[i] >> p[i+1];
    }
    for(int i=0; i<n+1; i++){
        m[i][i] = 0;
    }
    for(int l=2; l<=n; l++){
        for(int i=1; i<=n-l+1; i++){
            int j = i+l-1;
            m[i][j] = 1000000000;
            for(int k=i; k<=j-1; k++){
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }

    cout << m[1][n] << endl;
}