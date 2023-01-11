#include <bits/stdc++.h>
#define N 100
#define INF (1<<21)
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

int n, u=0, color[N], d[N], p[N];
int M[N][N];

void dijkstra(){
    for(int i=0; i<n; i++){
        d[i] = INF;
        color[i] = WHITE;
    }
    d[0] = 0;
    color[0] = GRAY;
    p[0] = -1;
    while(1){
        int mincost = INF;
        for(int v=0; v<n; v++){ // 伸ばす元となる頂点を決定
            if(color[v] != BLACK && d[v] < mincost){
                    mincost = d[v];
                    u = v;
            }
        }
        if(mincost == INF){
            break;
        }
        color[u] = BLACK; // ここまではprimのアルゴリズムと同じ(多分)
        for(int v=0; v<n; v++){ // 更新.
            if(color[v] != BLACK && M[u][v] != INF){
                if(d[u] + M[u][v] < d[v]){
                    d[v] = d[u] + M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << i << " " << d[i] << endl;
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M[i][j] = INF;
        }
    }
    for(int i=0; i<n; i++){
        int u, k;
        cin >> u >> k;
        for(int j=0; j<k; j++){
            int v, c;
            cin >> v >> c;
            M[u][v] = c;
        }
    }
    dijkstra();
}