#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 1e4 + 10 ;
const int inf = (int) 2e9 ;

struct edge{
    int u , w , used ;
    edge(){}
    edge( int _u , int _cost , int _used ) {
        u = _u , w = _cost , used = _used ;
    }
    bool operator < (const edge &p ) const {
        return w > p.w ;
    }
};

vector< edge > adj[N] ;
int level[15][N] ;

void init( int n ) {
    for( int i = 0 ; i <= n ; i++ ) {
        adj[i].clear() ;
        for( int j = 0 ; j < 15 ; j++ ) {
            level[j][i] = inf ;
        }
    }
}

int dij( int s , int t , int d ) {
    priority_queue< edge > pq ;
    pq.push( edge(s , 0 , 0) ) ;
    level[0][s] = 0 ;
    while( !pq.empty() ) {
        edge top = pq.top() ; pq.pop() ;
        int u = top.u , len = (int) adj[u].size() ;
        if( u == t ) return top.w ;
        for( int i = 0 ; i < len ; i++ ) {
            int v = adj[u][i].u ;
            int cost = top.w + adj[u][i].w ;
            int usd = top.used + adj[u][i].used ;
            if( level[usd][v] > cost && usd <= d ) {
                level[usd][v] = cost ;
                pq.push( edge(v , level[usd][v] , usd) ) ;
            }
        }
    }
    return -1 ;
}

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    int T , cas = 0 ; scanf("%d" , &T ) ;
    while( T-- ) {
        int n , m , k , d ; scanf("%d %d %d %d" , &n , &m , &k , &d ) ;
        init(n) ;
        for( int i = 1 ; i <= m ; i++ ) {
            int u , v , w ; scanf("%d %d %d" , &u , &v , &w ) ;
            u += 1 , v += 1 ;
            adj[u].push_back( edge(v , w , 0) ) ;
        }
        for( int i = 1 ; i <= k ; i++ ) {
            int u , v , w ; scanf("%d %d %d" , &u , &v , &w ) ;
            u += 1 , v += 1 ;
            adj[u].push_back( edge(v , w , 1) ) ;
        }
        int ans = dij(1 , n , d) ;
        printf("Case %d: " , ++cas ) ;
        if( ans == -1 ) printf("Impossible\n") ;
        else printf("%d\n" , ans ) ;
    }
    return 0 ;
}
