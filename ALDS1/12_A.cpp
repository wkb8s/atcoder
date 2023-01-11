#include <bits/stdc++.h>
#define N 100
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define INF (1<<21)
using namespace std;

int n, sum = 0;
int M[N][N];
int color[N], d[N], p[N];

int prim(){
    int u;
    for(int i=0; i<n; i++){
        color[i] = WHITE;
        d[i] = INF;
    }
    d[0] = 0;
    p[0] = -1;
    while(1){
        int mincost = INF;
        for(int i=0; i<n; i++){ // ここで頂点を選ぶ
            if(color[i] != BLACK && d[i] < mincost){
                mincost = d[i];
                u = i;
            }
        }
        if(mincost == INF){
            break;
        }
        color[u] = BLACK;
        for(int v=0; v<n; v++){
            if(color[v] != BLACK && M[u][v] != INF){
                if(M[u][v] < d[v]){
                    d[v] = M[u][v];
                    p[v] = u; // parent 本問では必要なさそう
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        sum += d[i];
    }
    return sum;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> M[i][j];
            if(M[i][j] == -1){
                M[i][j] = INF;
            }
        }
    }
    cout << prim() << endl;
}