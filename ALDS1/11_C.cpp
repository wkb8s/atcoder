#include <bits/stdc++.h>
#include <queue>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;
int d[N];
int M[N][N];
int color[N];
queue<int> q;

void bfs(int u){
    q.push(u);
    color[u] = GRAY;
    d[u] = 0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(M[u][i] && color[i] == WHITE){
                color[i] = GRAY;
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }
    color[u] = BLACK;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        d[i] = -1;
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
            int v=0;
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }
    bfs(0);
    for(int i=0; i<n; i++){
        cout << i+1 << " " << d[i] << endl;
    }
}