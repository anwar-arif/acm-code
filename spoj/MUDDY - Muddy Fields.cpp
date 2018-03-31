#include<bits/stdc++.h>
using namespace std;

const int N = (int) 50 + 10 ;

vector< int > adj[N * N] ;
char str[N][N] ;
int r , c , h , v , hor[N][N] , ver[N][N] ;
int match[N * N] ;
bool vis[N * N] ;

bool dfs( int u ) {
    int len = (int) adj[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = adj[u][i] ;
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
    memset( match , -1 , sizeof( match ) ) ;
    for( int i = 1 ; i <= h ; i++ ) {
        memset( vis , false , sizeof( vis ) ) ;
        ret += (int) dfs( i ) ;
    }
    return ret ;
}

int main() {
    int tst , cas = 0 ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        scanf("%d %d" , &r , &c ) ;
        for( int i = 0 ; i < r ; i++ ) {
            scanf("%s" , &str[i] ) ;
        }
        h = 0 , v = 0 ;
        for( int i = 0 ; i < r ; i++ ) {
            for( int j = 0 ;j  < c ; j++ ) {
                if( str[i][j] == '.' ) continue ;
                if( j == 0 ) hor[i][j] = ++h ;
                else if( str[i][j - 1] == '.' ) hor[i][j] = ++h ;
                else hor[i][j] = hor[i][j - 1] ;
            }
        }
        for( int j = 0 ; j < c ; j++ ) {
            for( int i = 0 ; i < r ; i++ ) {
                if( str[i][j] == '.' ) continue ;
                if( i == 0 ) ver[i][j] = ++v ;
                else if( str[i - 1][j] == '.' ) ver[i][j] = ++v ;
                else ver[i][j] = ver[i - 1][j] ;
            }
        }
        for( int i = 0 ; i <= h ; i++ ) adj[i].clear() ;
        for( int i = 0 ; i < r ; i++ ) {
            for( int j = 0 ; j < c ; j++ ) {
                if( str[i][j] == '*' ) {
                    adj[ hor[i][j] ].push_back( ver[i][j] ) ;
                }
            }
        }
        printf("%d\n" , bpm() ) ;
    }
    return 0 ;
}
