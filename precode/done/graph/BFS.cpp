#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

vector <int> adj[N];
int level[N], vis[N];
int nodes, edges;

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int s, int t) {
    queue <int> qu;
    qu.push(s);
    level[s] = 0, vis[s] = 1;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (int v: adj[u]) {
            if (vis[v] == 0) {
                qu.push(v);
                level[v] = level[u] + 1;
                vis[v] = 1;
            }
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < nodes; i++) {
        int u, v; scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    bfs(1, nodes);
    return 0;
}
