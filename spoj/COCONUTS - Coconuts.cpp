#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int

#define mem(a,x) memset(a,x,sizeof(a))

const int INF = 1e7;
const int MAXN = 310, MAXE = 135000;

int src, snk, nNode, nEdge;

int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];

int flow[MAXE], cap[MAXE], Next[MAXE], to[MAXE];

inline void init(int _src , int _snk , int _n){
    src = _src , snk = _snk , nNode = _n , nEdge = 0 ;
    mem( fin , -1 );
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
                dist[v] = dist[u]+1;
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

int main(){
    int n , m  , x , u , v ;
    while(scanf("%d%d",&n,&m) == 2){
        if(n == 0 && m == 0)break;
        init(0 , n+1 , n+10);
        for(int i = 1 ;i <= n;i++){
            scanf("%d",&x);
            if(x)add( 0 , i , 1);
            else add( i , n+1 , 1);
        }
        for(int i = 1 ;i <= m;i++){
            scanf("%d%d",&u , &v);
            add( u , v , 1 );
            add( v , u , 1 );
        }
        pf("%lld\n",dinitz());
    }
    return 0;
}
