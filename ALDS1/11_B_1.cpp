// 再帰を用いたDFS
#include <bits/stdc++.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int color[N];
int d[N], f[N];
int M[N][N];
int tt;

void dfs_visit(int u){
    color[u] = GRAY;
    d[u] = ++tt;
    for(int v=0; v<n; v++){
        if(M[u][v] == 0){
            continue;
        }
        if(color[v] == WHITE){
            dfs_visit(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs(){
    for(int i=0; i<n; i++){
        if(color[i] == WHITE){
            dfs_visit(i);
        }
    }
    for(int i=0; i<n; i++){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        color[i] = WHITE;
        for(int j=0; j<n; j++){
            M[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        int u, k;
        cin >> u >> k;
        u--;
        for(int j=0; j<k; j++){
            int v;
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    tt=0;
    dfs();
}