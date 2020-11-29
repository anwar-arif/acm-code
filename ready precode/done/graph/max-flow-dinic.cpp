#include<bits/stdc++.h>
using namespace std;

#define mem(p,x) memset(p, x, sizeof(p))
#define ll long long int

const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 60006;

int src, snk, nNode, nEdge;

int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];

int flow[MAXE], cap[MAXE], Next[MAXE], to[MAXE];

///Next[cur_edge_no] = previous edge_no from node u(edge u,v) of cur_edge_no
///fin[node] = latest outgoing edge_no from node u
///to[edge] = directied node number of edge (u,v)
///Q[] = queue<int>
///MAXE = 2*number_of_edge
///pro[] holds the heads of each linked list temporarily

inline void init(int _src, int _snk, int _n) {

    src = _src, snk = _snk, nNode = _n, nEdge = 0;

    mem(fin,-1);
}

inline void add(int u, int v, int c) {

    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, Next[nEdge] = fin[u], fin[u] = nEdge++;

    to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0, Next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    int st, en, i, u, v;
    mem(dist,-1);

    dist[src] = st = en = 0;
    Q[en++] = src;

    while(st < en) {
        u = Q[st++];

        for(i=fin[u]; i>=0; i=Next[i]) {

            v = to[i];

            if(flow[i] < cap[i] && dist[v]==-1) {

                dist[v] = dist[u]+1;/// dist is like level

                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {

    if(u==snk) return fl;

    for(int &e=pro[u], v, df; e>=0; e=Next[e]) {

        v = to[e];

        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {

            df = dfs(v, min(cap[e]-flow[e], fl));

            if(df>0) {

                flow[e] += df;
                flow[e^1] -= df;

                return df;
            }
        }
    }
    return 0;
}

ll dinitz() {

    ll ret = 0;
    int df;

    while(bfs()) {

        for(int i=0; i<=nNode; i++) pro[i] = fin[i];

        while(true) {

            df = dfs(src, INF);

            if(df) ret += (ll)df;

            else break;
        }
    }
    return ret;
}

int main() {
    int n, e, u, v, c, i;
    scanf("%d%d", &n, &e);

    init(1, n, n);

    for(i=0; i<e; i++) {

        scanf("%d%d%d", &u, &v, &c);

        if(u!=v) add(u, v, c);
    }

    printf("%lld\n", dinitz());
    return 0;
}
///complexity : n*n*m {n = nodes, m = edges}
///Using adjacency matrix and/or STL makes it 10 to 4 times slower.
///zobayer blogspot
