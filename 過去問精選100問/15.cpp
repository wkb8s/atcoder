#include <bits/stdc++.h>
#include <math.h>
using namespace std;

double len(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2,2));
}

int main() {
    int N, cnt=0;
    double sum = 0;
    cin >> N;
    int x[N], y[N], P[N];
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i];
        P[i] = i;
    }
    do{
        cnt++;
        for(int i=0; i<N-1; i++){
            sum += len(x[P[i]], y[P[i]], x[P[i+1]], y[P[i+1]]);
        }
    } while(next_permutation(P, P+N));
    cout << setprecision(10) << sum/cnt << endl;
}