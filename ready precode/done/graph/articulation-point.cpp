#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

vector <int> adj[N];
int nodes, edges, depth;
int par[N], vis[N], dis[N], low[N], art[N];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        vis[i] = 0, par[i] = -1, art[i] = 0;
        adj[i].clear();
    }
}

void dfs(int u) {
    vis[u] = 1;
    int child = 0;
    dis[u] = low[u] = depth++;

    for (int v: adj[u]) {
        if (!vis[v]) {
            par[v] = u, child += 1;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if (par[u] != -1) {
                if (dis[u] <= low[v]) {
                    art[u] = 1;
                }
            }
        } else if (v != par[u]) {
            low[u] = min(low[u], dis[v]);
        }
    }

    if (par[u] == -1 && child > 1) {
        art[u] = 1;
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    init(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= nodes; i++) {
        if (vis[i] == 0) {
            depth = 0;
            dfs(i);
        }
    }

    printf("Articulation points: ");

    for (int i = 1; i <= nodes; i++) {
        if (art[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
