// 隣接リスト利用ver
#include <bits/stdc++.h>
#define NIL -1
#define N 100000
using namespace std;

int n, m;
vector<int> G[N];
int color[N];

void dfs_visit(int u, int c){
    color[u] = c; //連結部分は同じ色で塗る
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if(color[v] == NIL){
            dfs_visit(v, c);
        }
    }
}

void dfs(){
    for(int i=0; i<n; i++){
        if(color[i] == NIL){
            dfs_visit(i, i);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    int q;
    cin >> q;
    for(int j=0; j<n; j++){
        color[j] = NIL;
    }
    dfs();
    for(int i=0; i<q; i++){
        int s, t;
        cin >> s >> t;
        if(color[s] == color[t]){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}