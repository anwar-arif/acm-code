#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

vector <int> adj[N];
int nodes, edges, deg[N];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        deg[i] = 0;
    }
}

void solve() {
    queue <int> qu;
    for (int i = 1; i <= nodes; i++) {
        if (deg[i] == 0) {
            qu.push(i);
        }
    }

    vector <int> res;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        res.push_back(u);

        for (int v: adj[u]) {
            --deg[v];
            if (deg[v] == 0) {
                qu.push(v);
            }
        }
    }

    printf("Topological order: ");
    for (int v: res) {
        printf("%d ", v);
    }
    printf("\n");
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    init(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        deg[v] += 1;
    }
    solve();

    return 0;
}

/*input :
5 4
1 2
2 3
1 3
1 5
output : 1 4 2 5 3*/
