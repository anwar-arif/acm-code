#include<bits/stdc++.h>
using namespace std;

const int N = 200+10;

bool removed[N], visited[N];
vector<int> adj[N];
int match[N], n, m, group[N];

bool dfs(int u) {
    if (removed[u]) return false;
    int len = (int) adj[u].size();
    for (int i = 0 ; i < len; i++) {
        int v = adj[u][i];
        if (!removed[v] && !visited[v]) {
            visited[v] = true;
            if (match[v] < 0 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++) {
        memset(visited,false, sizeof(visited));
        if (dfs(i)) ++cnt;
    }
    return cnt;
}

void reset() {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
}

int main() {
      int T, cas = 0; scanf("%d", &T);
      while(tst--){
          int n, m; scanf("%d %d", &n, &m);
          reset();
          for (int i = 0; i < n; i++) {
              scanf("%d", &group[i]);
          }
          for (int i = 0; i < m; i++) {
              int u, v; scanf("%d %d", &u, &v);
              if (group[u] != group[v]) {
                  if (group[u] == 0) {
                      adj[u].push_back(v);
                  } else {
                    adj[v].push_back(u);
                  }
              }
          }
          memset(removed, false, sizeof(removed));

          int total = bpm();
          printf("%d", total);

          int ans[N], k = 0;
          for (int i = 0; i < n; i++) {
              removed[i] = true;
              int cur = bpm();
              if (cur < tot) {
                  tot = cur;
                  ans[++k] = i;
                  if (tot == 0) break;
              } else {
                removed[i] = false;
              }
          }

          sort(ans + 1, ans + 1 + k);
          for (int i = 1; i <= k; i++) {
              printf(" %d", ans[i]);
          }
          printf("\n");
      }
      return 0;
}
