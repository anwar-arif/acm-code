#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e5 + 10 ;
const int inf = (int) 2e9 ;

struct edge{
    int u , w ;
    edge(){}
    edge( int _u , int _w ) {
        u = _u ; w = _w ;
    }
    bool operator < (const edge &p ) const {
        return w > p.w ;
    }
};

vector< int > adj[N] , cost[N] ;
int level[N] ;

void init( int nodes ) {
    for( int i = 0 ; i <= nodes ; i++ ) {
        adj[i].clear() ;
        cost[i].clear() ;
        level[i] = inf ;
    }
}

int Dij( int s , int t ) {
    priority_queue< edge > pq ;
    pq.push( edge(s , 0) ) ;
    level[s] = 0 ;
    while( !pq.empty() ) {
        edge top = pq.top() ; pq.pop() ;
        int u = top.u ;
        if( u == t ) return level[u] ;
        int len = (int) adj[u].size() ;
        for( int i = 0 ; i < len ; i++ ) {
            int v = adj[u][i] ;
            if( level[v] > level[u] + cost[u][i] ) {
                level[v] = level[u] + cost[u][i] ;
                pq.push( edge(v , level[v]) ) ;
            }
        }
    }
    return -1 ;
}

int main() {
    int n , m , s , t ;
    init( n ) ;
    scanf("%d %d %d %d" , &n , &m , &s , &t ) ;
    for( int i = 1 ; i <= n ; i++ ) {
        int u , v , c ; scanf("%d %d %d" , &u , &v , &c ) ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
        cost[u].push_back(c) ;
        cost[v].push_back(c) ;
    }
    int ans = Dij( s , t ) ;
    if( ans == -1 ) printf("Not Reachable\n") ;
    else printf("Minimum Distance %d\n" , ans ) ;
    return 0 ;
}
