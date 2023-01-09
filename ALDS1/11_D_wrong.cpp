// このコードだとメモリが足りなくなる
// nが小さければこのコードでも動く
#include <bits/stdc++.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 1000 // メモリが不足しないよう意図的に制限
#define Q 1000 // 上に同じ
using namespace std;

int n, m, cnt = 0;
int M[N][N];
int color[N];
bool arrive[Q];

void dfs_visit(int u, int goal){
    color[u] = GRAY;
    for(int v=0; v<n; v++){
        if(M[u][v] == 1 && color[v] == WHITE){
            dfs_visit(v, goal);
            if(v == goal){
                arrive[cnt] = true;
            }
        }
    }
    color[u] = BLACK;
}

void dfs(int s, int t){
    dfs_visit(s, t);
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M[i][j] = 0;
        }
    }
    for(int i=0; i<m; i++){
        int s, t;
        cin >> s >> t;
        M[s][t] = 1;
        M[t][s] = 1;
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        arrive[i] = false;
    }
    for(int i=0; i<q; i++){
        int s, t;
        cin >> s >> t;
        for(int j=0; j<n; j++){
            color[j] = WHITE;
        }
        dfs(s, t);
        cnt++;
    }
    for(int i=0; i<q; i++){
        if(arrive[i]){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}