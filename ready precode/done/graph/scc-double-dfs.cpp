#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 10;
const int inf = (int) 2e9;

stack<int> st;
bool visited[N], color[N];
vector<int> components[N], graph[N], reverse_graph[N];

void dfs(int u) {
    color[u] = true;
    int len = (int) graph[u].size();

    for (int i = 0; i < len; i++) {
        int v = graph[u][i];
        if (color[v] == false) {
            dfs(v);
        }
    }
    st.push(u);
    return;
}

void dfs2(int u, int mark) {
    components[mark].push_back(u); ///mark = scc number
    visited[u] = true;

    int len = (int) reverse_graph[u].size();
    for (int i = 0; i < len; i++) {
        int v = reverse_graph[u][i];///reverse
        if (visited[v] == false) {
            dfs2(v, mark);
        }
    }

    return;
}

int main() {
      int T; scanf("%d", &T);
      while (T--) {
        int n, m; scanf("%d %d", &n, &m);

        for (int i = 0; i <= n + 2; i++) {
            components[i].clear();
            graph[i].clear();
            reverse_graph[i].clear();
        }

        for (int i = 1; i <= m; i++) {
            int from, to; scanf("%d %d", &from, &to);
            graph[from].push_back(to);
            reverse_graph[to].push_back(from);
        }

        while (!st.empty()) {
            st.pop();
        }

        memset(visited, false, sizeof(visited));
        memset(color, false, sizeof(color));

        for (int i = 1; i <= n; i++) {
            if (color[i] == false) {
                dfs(i);
            }
        }

        int cnt = 0;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (visited[u] == false) {
                dfs2(u, ++cnt);
            }
        }

        printf("total scc %d\n", cnt);
      }
      return 0;
}
//if the cycle remains same in reverse graph then these cycle is a scc
