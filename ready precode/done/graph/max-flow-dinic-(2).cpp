#include<bits/stdc++.h>
using namespace std;

const int inf = 0x7fffffff;
const int MAXN = 5005, MAXE = 60006 ;

int src , snk , nNode , nEdge ;

int Q[MAXN] , fin[MAXN] , pro[MAXN] , dist[MAXN] ;

int flow[MAXE] , cap[MAXE] , Next[MAXE] , to[MAXE] ;

///Next[cur_edge_no] = previous edge_no from node u(edge u,v) of cur_edge_no
///fin[node] = latest outgoing edge_no from node u
///to[edge] = directied node number of edge (u,v)
///Q[] = queue<int>
///MAXE = 2*number_of_edge
///pro[] holds the heads of each linked list temporarily

inline void init( int _src, int _snk, int _n ) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    memset( fin , -1 , sizeof(fin) ) ;
}

inline void add( int u , int v , int c ) {
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, Next[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0, Next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    int st, en ;
    memset( dist , -1 , sizeof(dist) ) ;

    dist[src] = st = en = 0 ;
    Q[en++] = src;

    while(st < en) {
        int u = Q[st++] ;
        for(int i = fin[u] ; i >= 0 ; i = Next[i] ) {
            int v = to[i] ;
            if( flow[i] < cap[i] && dist[v] == -1 ) {
                dist[v] = dist[u] + 1 ;/// dist is like level
                Q[en++] = v;
            }
        }
    }
    return ( dist[snk] != -1 ) ;
}

int dfs( int u , int fl ) {
    if( u == snk ) return fl ;
    for( int &e = pro[u] ; e >= 0 ; e = Next[e] ) {
        int v = to[e] ;
        if( flow[e] < cap[e] && dist[v] == dist[u] + 1 ) {
            int df = dfs( v , min( cap[e]-flow[e] , fl ) ) ;
            if( df > 0 ) {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

long long dinitz() {
    long long ret = 0;
    while( bfs() ) {
        for(int i = 0 ; i <= nNode ; i++ ) pro[i] = fin[i] ;
        while(true) {
            int df = dfs( src , inf ) ;
            if( df ) ret += (long long) df ;
            else break;
        }
    }
    return ret;
}

int main() {
    int n, e ;
    scanf("%d%d", &n, &e);

    init(1, n, n);

    for(int i=0; i<e; i++) {
        int u , v , c ; scanf("%d %d %d", &u, &v, &c) ;
        if( u != v ) add(u, v, c) ;
    }

    printf("%lld\n", dinitz());
    return 0;
}
///complexity : n*n*m {n = nodes, m = edges}
///Using adjacency matrix and/or STL makes it 10 to 4 times slower.
///zobayer blogspot
