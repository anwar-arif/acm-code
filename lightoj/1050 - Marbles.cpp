#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 500 + 10 ;
const int inf = (int) 2e9 ;

int vis[N][N][3] ;
double dp[N][N][3] ;

double F( int r , int b , int t ) {
    if( dp[r][b][t] > -0.5 ) return dp[r][b][t] ;
    if( r + b == 1 ) {
        return dp[r][b][t] = b ? 1.0 : 0.0 ;
    }
    if( t == 0 ) {
        double ans = 0.0 ;
        if( r > 0 ) ans += F(r - 1 , b , 1 - t) * (r + 0.0) / (r + b + 0.0) ;
        if( b > 0 ) ans += F(r , b - 1 , 1 - t) * (b + 0.0) / (r + b + 0.0) ;
        return dp[r][b][t] = ans ;
    }
    if( b > 0 ) {
        return F(r , b - 1 , 1 - t) ;
    }
    return dp[r][b][t] = 0.0 ;
}

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    for( int i = 0 ; i < N ; i++ )
        for( int j = 0 ; j < N ; j++ )
            for( int k = 0 ; k < 2 ; k++ )
                dp[i][j][k] = -1 ;
    memset( vis , 0 , sizeof(vis) ) ;
    int T , cas = 0 ; scanf("%d" , &T ) ;
    while( T-- ) {
        int r , b ; scanf("%d %d" , &r , &b ) ;
        printf("Case %d: %0.9f\n" , ++cas , F(r , b, 0) ) ;
    }
    return 0 ;
}
