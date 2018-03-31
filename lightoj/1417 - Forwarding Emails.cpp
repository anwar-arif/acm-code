#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 50000 + 10 ;

vector < int > adj[N] , graph[N] , SCC[N] ;

int dis[N] , fin[N] , in_stack[N] , parent[N] , belong[N] , sz[N] , dp[N] ;
int scc_cnt = 0 , tym = 0 ;
stack< int > stk ;

void Tarjan( int u , int root = 1 ) {
    fin[u] = dis[u] = ++tym ;
    in_stack[u] = 1 ;
    stk.push(u) ;

    int len = (int) adj[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = adj[u][i] ;
        if( fin[v] == -1 ) {

            Tarjan(v) ;
            dis[u] = min( dis[v] , dis[u] ) ;
        }

        else if( in_stack[v] == 1 ) {
            dis[u] = min( dis[u] , fin[v] ) ;
        }
    }

    if( fin[u] == dis[u] ) {
        ++scc_cnt ;
        while( !stk.empty() && fin[u] <= dis[stk.top()] ) {
            SCC[scc_cnt].push_back( stk.top() ) ;
            belong[stk.top()] = scc_cnt ;
            in_stack[ stk.top() ] = 0 ;
            stk.pop() ;
        }
    }
}

int rec( int u ) {
    if( dp[u] != -1 ) return dp[u] ;
    int ans = sz[ belong[u] ] , len = (int) graph[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        ans = max( ans , rec( graph[u][i] ) + sz[ belong[u] ] ) ;
    }
    return dp[u] = ans ;
}

int solve( int nodes ) {
    for( int i = 1 ; i <= nodes ; i++ ) {
        if( fin[i] == -1 ) Tarjan( i ) ;
    }
    for( int i = 1 ; i <= nodes ; i++ ) {
        int len = (int) adj[i].size() ;
        for( int j = 0 ; j < len ; j++ ) {
            if( belong[i] != belong[adj[i][j]] ) {
                graph[i].push_back( adj[i][j] ) ;
            }
        }
    }
    for( int i = 1 ; i <= nodes ; i++ ) ++sz[ belong[i] ] ;
    int ans = -1 , mx = -1 ;
    for( int i = 1 ; i <= nodes ; i++ ) {
        if( rec(i) > mx ) {
            ans = i ; mx = rec(i) ;
        }
    }
    return ans ;
}

void input( int ed ) {
    for( int i = 1 ; i <= ed ; i++ ) {
        int u , v ; scanf("%d %d" , &u , &v ) ;
        adj[u].push_back(v) ;
    }
}

void init( int nodes ) {
    for( int i = 0 ; i <= nodes ; i++ ) {
        adj[i].clear() ; graph[i].clear() ;
        dis[i] = fin[i] = -1 ;
        in_stack[i] = 0 ;
        parent[i] = i ;
        sz[i] = 0 ;
        dp[i] = -1 ;
    }
    scc_cnt = 0 , tym = 0 ;
    while( !stk.empty() ) stk.pop() ;
}

int main() {
    int tst , cas = 0 ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        int n ; scanf("%d" , &n ) ;
        init( n ) ;
        input( n ) ;
        printf("Case %d: %d\n" , ++cas , solve(n) ) ;
    }
    return 0 ;
}
