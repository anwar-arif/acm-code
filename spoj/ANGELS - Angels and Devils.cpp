#include<bits/stdc++.h>
using namespace std ;

const int N = 500 + 10 ;

vector<int>graph[N*N];

int match[N*N] , h , v ;
bool vis[N*N] ;

bool dfs( int u ) {
    int len = (int) graph[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = graph[u][i] ;
        if( !vis[v] ) {
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
    for( int i = 1 ; i <= h ; i++ ) {
        memset( vis , false , sizeof(vis) ) ;
        if( dfs(i) ) {
            ++ret ;
        }
    }
    return ret ;
}

int hor[N][N] , ver[N][N] ;
char str[N][N] ;

int main() {
    int tst , cas = 0 , r , c ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        scanf("%d %d" , &r , &c ) ;
        h = 0 , v = 0 ;
        for( int i = 0 ; i < r ; i++ ) {
            for( int j = 0 ; j < c ; j++ ) {
                scanf(" %c" , &str[i][j] ) ;
            }
        }
        for( int i = 0 ; i < r ; i++ ) {
            for( int j = 0 ; j < c ; j++ ) {
                if( j == 0 || str[i][j] == 'A' ) {
                    hor[i][j] = ++h ;
                } else {
                    hor[i][j] = hor[i][j - 1] ;
                }
                if( i == 0 || str[i][j] == 'A' ) {
                    ver[i][j] = ++v ;
                }else {
                    ver[i][j] = ver[i - 1][j] ;
                }
            }
        }
        for( int i = 0 ; i <= h ; i++ ) graph[i].clear() ;
        for( int i = 0 ; i < r ; i++ ) {
            for( int j = 0 ; j < c ; j++ ) {
                if( str[i][j] == 'H' ) {
                    graph[ hor[i][j] ].push_back( ver[i][j] ) ;
                }
            }
        }
        printf("%d\n" , bpm() ) ;
    }
    return 0 ;
}
