#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

vector <int> adj[N];
int n, m;
int match[N], vis[N];

bool dfs(int u) {
    for (int v: adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    int ret = 0;
    memset(match, -1, sizeof(match));

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) {
            ret += 1;
        }
    }

    return ret;
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int u = 1; u <= n; u++) {
        int prefer; scanf("%d", &prefer);
        for (int j = 1; j <= prefer; j++) {
            int v; scanf("%d", &v);
            adj[u].push_back(v);
        }
    }

    int answer = bpm();
    printf("%d\n", answer);

    return 0;
}
/**
    complexity = N*(M+E)
    N = size of set A
    M = size of set B
    E = total edges
*/
