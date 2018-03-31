#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e5 + 10 ;
const int inf = (int) 2e9 ;

vector< int > adj[N] ;
int qu[N] , level[N] , vis[N] ;

void bfs( int s , int t ) {
    int l = 0 , r = 0 ;
    qu[r++] = s ;
    level[s] = 0 ; vis[s] = 1 ;
    while( l < r ) {
        int u = qu[l++] ;
        int len = (int) adj[u].size() ;
        for( int i = 0 ; i < len ; i++ ) {
            int v = adj[u][i] ;
            if( vis[v] == 0 ) {
                level[v] = level[u] + 1 ;
                par[v] = u ;
                vis[v] = 1 ;
                qu[r++] = v ;
            }
        }
    }
}

void init( int nodes ) {
    for( int i = 0 ; i <= nodes ; i++ ) {
        par[i] = i ; vis[i] = 0 ;
    }
}

int main() {
    int n , m ; scanf("%d %d" , &n , &m ) ;
    init( n ) ;
    for( int i = 1 ; i <= n ; i++ ) {
        int u , v ; scanf("%d %d" , &u , &v ) ;
        adj[u].push_back(u) ;
        adj[v].push_back(v) ;
    }
    bfs(1 , n) ;
    return 0 ;
}
