#include<bits/stdc++.h>
using namespace std ;

const int N = 40 + 10 ;

int arr[N][N] ;

int dp[N][N][N][N] , vis[N][N][N][N] , cas = 0 ;
int row , col ;

int getMin( int x1 , int y1 , int x2 , int y2 ){
    int mn = 10000000 ;
    for( int i = x1 ; i <= x2 ; i++ ) {
        for( int j = y1 ; j <= y2 ; j++ ) {
            mn = min( mn , arr[i][j] ) ;
        }
    }
    return mn ;
}

int rec( int x1 , int y1 , int x2 , int y2 ) {
    if( vis[x1][y1][x2][y2] == cas ) return dp[x1][y1][x2][y2] ;
    vis[x1][y1][x2][y2] = cas ;

    if( x1 == x2 && y1 == y2 ) {
        return 0 ;
    }
    int &ret = dp[x1][y1][x2][y2] ;
    int nw = getMin( x1 , y1 , x2 , y2 ) ;
    int mx = -100 ;
    for( int i = x1 ; i < x2 ; i++ ) {
        mx = max( mx , rec( x1 , y1 , i , y2) + rec( i+1 , y1 , x2 , y2 ) ) ;
    }
    for( int i = y1 ; i < y2 ; i++ ) {
        mx = max( mx , rec( x1 , y1 , x2 , i ) + rec( x1 , i+1 , x2 , y2 )  ) ;
    }
    return ret = nw + mx ;
}

int main() {
//    freopen("C-large.in" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout ) ;
    int tst ;
    scanf("%d" , &tst ) ;
    memset( vis , 0 , sizeof(vis) ) ;
    while( tst-- ) {
        ++cas ;
        scanf("%d %d" , &row , &col ) ;
        for( int i = 1 ; i <= row ; i++ ){
            for( int j = 1 ; j <= col ; j++ ) {
                scanf("%d" , &arr[i][j] ) ;
            }
        }
        int ans = rec( 1 , 1 , row , col ) ;
        printf("Case #%d: %d\n" , cas , ans ) ;
    }
    return 0 ;
}
