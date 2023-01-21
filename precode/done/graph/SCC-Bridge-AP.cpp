#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 1e5 + 10 ;

vector< int > adj[N] , SCC[N] ;
stack< int > stk ;
vector< pair< int , int > > bridge ;
vector< int > AP ;

int scc_cnt, tym, in_stack[N], fin[N], dis[N] , parent[N] ;

void Tarjan( int u , int root = 1 ) {
    ///param - "int root" //for Articulation Point
    fin[u] = dis[u] = ++tym ;
    in_stack[u] = 1 ;
    stk.push(u) ;

//    int child = 0 ; //for Articulation Point
    int len = (int) adj[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = adj[u][i] ;
        if( fin[v] == -1 ) {
//            parent[v] = u ; ///for Articulation Point & Bridge

            Tarjan(v) ;
            dis[u] = min( dis[v] , dis[u] ) ;

//            if( fin[u] < dis[v] ) bridge.push_back( make_pair(min(u, v), max(u, v))) ; ///for Bridge
//            if( fin[u] <= dis[v] && u != root ) AP.push_back(u) ; ///for Articulation Point
//            child++ ; ///for Articulation Point
        }

        else if( in_stack[v] == 1 ) {
//            if( parent[u] != v ) ///for Articulation Point & Bridge
                dis[u] = min( dis[u] , fin[v] ) ;
        }
//        if( u == root && child > 1 ) AP.push_back(u) ;
    }

    if( fin[u] == dis[u] ) {
        ++scc_cnt ;
        while( !stk.empty() && fin[u] <= dis[stk.top()] ) {
            SCC[scc_cnt].push_back( stk.top() ) ;
            in_stack[ stk.top() ] = 0 ;
            stk.pop() ;
        }
    }
}

void input( int edges ) {
    for( int i = 0 ; i < edges ; i++ ) {
        int u , v ; scanf("%d %d" , &u , &v ) ;
        adj[u].push_back(v) ;
//        adj[v].push_back(u) ;
    }
}

void solve( int nodes ) {
    for( int i = 1 ; i <= nodes ; i++ ) {
        if( fin[i] == -1 ) Tarjan(i) ;
    }
}

void init( int nodes ) {
    tym = 0 , scc_cnt = 0 ;
    for( int i = 0 ; i <= nodes ; i++ ) {
        adj[i].clear() ;
        SCC[i].clear() ;
        parent[i] = i ;
        fin[i] = -1 ;
    }
    bridge.clear() ;
    AP.clear() ;
    while( !stk.empty() ) stk.pop() ;
}

int main() {
    int n , e ;
    scanf("%d %d" , &n , &e ) ;

    init( n ) ;
    input( e ) ;
    solve( n ) ;

    printf("Total scc %d\n" , scc_cnt ) ;

    for( int i = 1 ; i <= scc_cnt ; i++ ) {
        for( int j = 0 ; j < SCC[i].size() ; j++) {
             printf("%d ", SCC[i][j]);
        }
        printf("\n") ;
    }

    for( int i = 0 ; i < (int) bridge.size() ; i++ ) {
        printf("bridge %d - %d\n" , bridge[i].first , bridge[i].second ) ;
    }
    return 0;
}
/**
SCC works in directed graph , complexity O(V + E)
bridge and AP works in undirected graph , complexity O(V + E)
*/
