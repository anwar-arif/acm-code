#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

struct edge {
    int u, v, w;
    edge(){}
    edge(int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }
    bool operator < (const edge &p) const {
        return w < p.w;
    }
};

vector <edge> adj;
int par[N], nodes, edges;

void init(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    adj.clear();
}

int findpar(int r) {
    return (par[r] == r) ? r : par[r] = findpar(par[r]);
}

void mst() {
    sort(adj.begin(), adj.end());
    int cnt = 0, sum = 0;
    int len = (int) adj.size();
    for (int i = 0; i < len; i++) {
        int u = findpar(adj[i].u);
        int v = findpar(adj[i].v);
        if (u != v) {
            par[u] = v;
            cnt += 1;
            sum += adj[i].w;
            if (cnt == nodes - 1) break;
        }
    }
    printf("mst: %d\n", sum);
}

/**
 * Sorting the edges takes O(ElogE) where E = number of edges
 * So, overall time complexity is O(ElogE)
*/

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    init(nodes);
    for (int i = 0; i < edges; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adj.push_back(edge(u, v, w));
    }
    mst();
    return 0;
}
