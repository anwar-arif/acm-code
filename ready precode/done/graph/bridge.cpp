#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 10 ;

int vis[N] , par[N] , fin[N] , dis[N] ;
vector< pair< int , int > > bridge ;
vector< int > adj[N] ;

int n , edge , depth ;

void dfs( int u ) {
    vis[u] = 1 ;
    fin[u] = dis[u] = depth++ ;
    int len = (int) adj[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = adj[u][i] ;
        if( par[u] != v ) {
            if( !vis[v] ) {
                par[v] = u ;
                dfs( v ) ;
                if( fin[u] < dis[v] ) {
                    bridge.push_back( make_pair( min(u , v) , max(u , v) )) ;
                }
                dis[u] = min( dis[u] , dis[v] ) ;
            }
            else {
                dis[u] = min( dis[u] , fin[v] ) ;
            }
        }
    }
}

int main() {
    scanf("%d" , &n ) ;
    scanf("%d" , &edge ) ;
    for( int i = 0 ; i < edge ; i++ ) {
        int u , v ; scanf("%d %d" , &u , &v ) ;
        adj[u].push_back(v) ;
    }
    for( int i = 1 ; i <= n ; i++ ) {
        if( !vis[i] ) dfs( i ) ;
    }
    sort( bridge.begin() , bridge.end() ) ;
    printf("Total Bridge = %d\n" , bridge.size() ) ;
    for( int i = 0 ; i < bridge.size() ; i++ ) {
        printf("%d - %d\n" , bridge[i].first , bridge[i].second ) ;
    }
    return 0 ;
}
/*
complexity O(V + E)
works in undirected graph
*/
