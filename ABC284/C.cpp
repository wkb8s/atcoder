#include <bits/stdc++.h>
#define MAX 100
#define UNVISITED -1
#define VISITED 1
using namespace std;

int cnt = 0;
int N, M;
int color[MAX];
vector<int> G[MAX];

void dfs_visit(int u){
    color[u] = VISITED;
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if(color[v] == UNVISITED){
            dfs_visit(v);
        }
    }
}

void dfs(){
    for(int i=0; i<N; i++){
        if(color[i] == UNVISITED){
            dfs_visit(i);
            cnt++;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0; i<N; i++){
        color[i] = UNVISITED;
    }
    dfs();
    cout << cnt << endl;
}