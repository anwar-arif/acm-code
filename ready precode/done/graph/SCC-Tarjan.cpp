#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

vector <int> adj[N], SCC[N];
stack <int> stk;
int nodes, edges, scc_cnt = 0, depth = 0;
int in_stack[N], dis[N], low[N];

void init(int n) {
    scc_cnt = 0, depth = 0;
    for (int i = 0; i <= n; i++) {
        adj[i].clear(), SCC[i].clear();
        dis[i] = -1, in_stack[i] = 0;
    }
    while (!stk.empty()) stk.pop();
}

void Tarjan(int u, int root = 1) {
    dis[u] = low[u] = depth++;
    in_stack[u] = 1;
    stk.push(u);

    for (int v: adj[u]) {
        if (dis[v] == -1) {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v] == 1) {
            low[u] = min(low[u], dis[v]);
        }
    }

    if (dis[u] == low[u]) {
        ++scc_cnt;
        while (!stk.empty() && low[u] <= dis[stk.top()]) {
            SCC[scc_cnt].push_back(stk.top());
            in_stack[stk.top()] = 0;
            stk.pop();
        }
    }
}

void solve() {
    for (int i = 1; i <= nodes; i++) {
        if (dis[i] == -1) {
            Tarjan(i);
        }
    }

    for (int i = 1; i <= scc_cnt; i++) {
        for (int v: SCC[i]) {
            printf("%d ", v);
        }
        printf("\n");
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    init(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    solve();

    return 0;
}
