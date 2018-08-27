#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 1e5 + 5 ;
const int inf = (int) 2e9 ;

vector< int > adj[N] ;
int coin[N] , vis[N] , id = 0 , xr ;

void dfs( int u , int p , int d ) {
    if( coin[u] & 1 ) xr ^= d ;
    vis[u] = id ;
    for( int v : adj[u] ) {
        if( vis[v] != id ) {
            dfs(v , u , d + 1) ;
        }
    }
}

int main(){
//    freopen("in.txt" , "r" , stdin ) ;
    memset( vis , 0 , sizeof(vis) ) ;
    int T , cas = 0 ; scanf("%d" , &T ) ;
    while( T-- ) {
        int n ; scanf("%d" , &n ) ;
        for( int i = 0 ; i <= n ; i++ ) {
            adj[i].clear() ;
        }
        for( int i = 1 ; i <= n ; i++ ) scanf("%d" , &coin[i] ) ;
        for( int i = 1 ; i < n ; i++ ) {
            int u , v ; scanf("%d %d" , &u , &v ) ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        int ans = 0 ;
        for( int i = 1 ; i <= n ; i++ ) {
            id += 1 ;
            xr = 0 ;
            dfs(i , i , 0) ;
            if( xr == 0 ) ans += 1 ;
        }
        printf("Case %d: %d\n" , ++cas , ans ) ;
    }
    return 0 ;
}

