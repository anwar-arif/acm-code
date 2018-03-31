#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 200 + 10 ;

vector<int>graph[N] , arr ;

int match[N] , n ;
bool vis[N] , removed[N] ;

bool dfs( int u ) {
    if( removed[u] ) return false ;
    int len = (int) graph[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = graph[u][i] ;
        if( !removed[v] && !vis[v] ) {
            vis[v] = true ;
            if( match[v] == -1 || dfs( match[v] ) ) {
                match[v] = u ;
                return true ;
            }
        }
    }
    return false ;
}

int bpm() {
    int ret = 0 ;
    memset( match , -1 , sizeof(match) ) ;
    for( int i = 1 ; i <= n ; i++ ) {
        memset( vis , false , sizeof(vis) ) ;
        if( dfs(i) ) {
            ++ret ;
        }
    }
    return ret ;
}

int main() {
    scanf("%d" , &n ) ;
    for( int i = 1 ; i <= n ; i++ ) {
        int x ;scanf("%d" , &x ) ;
        arr.push_back(x) ;
        removed[i] = false ;
    }
    sort( arr.begin() , arr.end() ) ;
    arr.erase( unique(arr.begin() , arr.end()) , arr.end() ) ;
    n = arr.size() ;
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = i + 1 ; j <= n ; j++ ) {
            if( i == j ) continue ;
            if( arr[j - 1] % arr[i - 1] == 0 )graph[i].push_back(j) ;
        }
    }
    int tot = bpm() , cnt = 0 ;
    printf("%d\n" , n - tot ) ;
    for( int i = 1 ; i <= n ; i++ ) {
        removed[i] = true ;
        if( bpm() < tot ) {
            --tot ;
        }else {
            removed[i] = false ;
            if( cnt ) printf(" ") ;
            printf("%d" , arr[i - 1] ) ;
            ++cnt ;
        }
    }
    printf("\n") ;
    return 0 ;
}

