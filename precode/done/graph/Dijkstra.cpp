#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

struct edge {
    int u, w;
    edge(){}
    edge(int _u, int _w) {
        u = _u, w = _w;
    }
    bool operator < (const edge &p) const {
        return w > p.w;
    }
};

vector <pair<int, int>> adj[N];
int nodes, edges, level[N];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        level[i] = inf;
    }
}

int Dij(int s, int t) {
    priority_queue <edge> pq;
    pq.push(edge(s, 0));
    level[s] = 0;

    while (!pq.empty()) {
        edge top = pq.top(); pq.pop();
        int u = top.u;
        if (u == t) return level[u];

        for (auto p: adj[u]) {
            int v = p.first, c = p.second;
            if (level[u] + c < level[v]) {
                level[v] = level[u] + c;
                pq.push(edge(v, level[v]));
            }
        }
    }

    return -1;
}

/**
 * TIme complexity O(E + VlogV) where E = number of edges, V = number of nodes
 * Here, priority_queue takes O(VlogV) to sort the nodes
*/

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    int s, t; scanf("%d %d", &s, &t);
    init(nodes);

    for (int i = 1; i <= nodes; i++) {
        int u, v, c; scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    int answer = Dij(s, t);
    if (answer == -1) printf("Not Reachable\n");
    else printf("Minimum Distance %d\n", answer);

    return 0;
}
