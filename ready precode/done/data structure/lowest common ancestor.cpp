#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;
const int LOG = 20;

vector <int> adj[N];
int level[N], par[N][LOG + 5];
int nodes, edges, queries, root = 1;

void dfs(int u, int p, int d) {
    level[u] = d;
    for (int v: adj[u]) {
        if (v != p) {
            par[v][0] = u;
            dfs(v, u, d + 1);
        }
    }
}

void buildLca() {
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= LOG; j++) {
            par[i][j] = -1;
        }
    }

    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i <= nodes; i++) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
                ///as 2^(x-1) + 2^(x-1) = 2^x
            }
        }
    }
}

int queryLca(int p, int q) {
    if (level[p] < level[q]) swap(p, q);

    for (int i = LOG; i >= 0; i--) {
        if (level[p] - (1 << i) >= level[q]) {
            p = par[p][i];
        }
    }

    if (p == q) return p;

    for (int i = LOG; i >= 0; i--) {
        if (par[p][i] != -1 && par[p][i] != par[q][i]) {
            p = par[p][i];
            q = par[q][i];
        }
    }

    return par[p][0];
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    for (int i = 1; i <= edges; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    par[root][0] = root;

    dfs(root, root, 0);
    buildLca();

    scanf("%d", &queries);

    while (queries--) {
        int u, v; scanf("%d %d", &u, &v);
        printf("%d\n", queryLca(u, v));
    }

    return 0;
}
