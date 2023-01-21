#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e3 + 10;
const int inf = (int) 2e9;

int parent[N], cost[N][N], n;
vector<int> adj[N];

bool bfs(int s, int target) {
    parent[src] = src;
    vector<bool> visited(n + 2, false);
    queue<int> qu;

    qu.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int len = (int) adj[u].size();

        for (int i = 0; i < len; i++) {
            int v = adj[u][i];
            if (visited[v] == false && cost[u][v] > 0) {
                visited[v] = true;
                parent[v] = u;

                if (v == target) return true;
                qu.push(v);
            }
        }
    }

    return visited[target];
}

int fordFulkerson(int src, int target){
    int mx_flow = 0;

    while (bfs(src, target) == true) {

        int path_flow = INT_MAX;

        for (int v = target; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, cost[u][v]);
        }

        for (int v = target; v != s; v = parent[v]) {
            int u = parent[v];
            cost[u][v] -= path_flow;
            cost[v][u] += path_flow;
        }

        mx_flow += path_flow;
    }

    return mx_flow;
}

int main() {
      int T, cas = 0;
      scanf("%d", &T);
      while (T--) {
          int n; scanf("%d", &n);
          int src, target, edges;
          scanf("%d %d %d", &src, &target, &edges);

          for (int i = 0; i <= n; i++) {
              adj[i].clear();
              for (int j = 0; j <= n; j++) {
                  cost[i][j] = 0;
              }
          }

          for (int i = 0; i < e; i++) {
              int u, v, w; scanf("%d %d %d", &u, &v, &w);
              adj[u].push_back(v);
              adj[v].push_back(u);
              cost[u][v] += w;
              cost[v][u] += w;
          }
          printf("Case %d: %d\n", ++cas, fordFulkerson(src, target));
      }
      return 0;
}
/*
    complexity : maxflow*Edges
*/
