#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 150000 + 10 ;
const int NIL = 0 ;
const int inf = (1 << 28) ;

vector< int > adj[N] ;
int n , m , match[N] , dist[N] ;

bool bfs() {
    queue< int > qu ;
    for( int i = 1 ; i <= n ; i++ ) {
        if( match[i] == NIL ) {
            dist[i] = 0 ;
            qu.push( i ) ;
        }
        else {
            dist[i] = inf ;
        }
    }
    dist[NIL] = inf ;
    while( !qu.empty() ) {
        int u = qu.front() ; qu.pop() ;
        if( u != NIL ) {
            int len = (int) adj[u].size() ;
            for( int i = 0 ; i < len ; i++ ) {
                int v = adj[u][i] ;
                if( dist[ match[v] ] == inf ) {
                    dist[ match[v] ] = dist[u] + 1 ;
                    qu.push( match[v] ) ;
                }
            }
        }
    }
    return ( dist[NIL] != inf ) ;
}

bool dfs( int u ) {
    if( u != NIL ) {
        int len = (int) adj[u].size() ;
        for( int i = 0 ; i < len ; i++ ) {
            int v = adj[u][i] ;
            if( dist[ match[v] ] == dist[u] + 1 ) {
                if( dfs( match[v] ) ) {
                    match[v] = u ;
                    match[u] = v ;
                    return true ;
                }
            }
        }
        dist[u] = inf ;
        return false ;
    }
    return true ;
}

int hopcroft_karp() {
    int matching = 0 ;
    while( bfs() ) {
        for( int i = 1 ; i <= n ; i++ ) {
            if( match[i] == NIL && dfs(i) ) {
                ++matching ;
            }
        }
    }
    return matching ;
}

int main() {
    int p ;
    scanf("%d %d %d" , &n , &m , &p ) ;
    while( p-- ) {
        int u , v ; scanf("%d %d" , &u , &v ) ;
        v += n ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    printf("%d\n" , hopcroft_karp() ) ;
    return 0 ;
}
/**
    complexity = sqrt(V)*E
    V = total nodes , E = edges
*/

