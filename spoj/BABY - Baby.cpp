#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 17 ;
const int inf = (int) 2e9 ;

int dp[N][(1 << N)] , a[N] , b[N] , n ;
int vis[N][(1 << N)] , cas = 0 ;

int C( int i , int j ) {
    return ( abs(i - j) + abs(a[i] - b[j]) ) ;
}

int F( int i , int mask ) {
    if( i >= n ) return 0 ;

    int &v = vis[i][mask] ;
    int &ret = dp[i][mask] ;

    if( v == cas ) return ret ;
    v = cas ;

    ret = inf ;
    for( int j = 0 ; j < n ; j++ ) {
        if( (mask & (1 << j)) == 0 ) {
            ret = min( ret , C(i , j) + F(i + 1 , (mask | (1 << j)) ) ) ;
        }
    }

    return ret ;
}

int main(){
//    freopen("in.txt" , "r" , stdin ) ;
    memset( vis , 0 , sizeof(vis) ) ;
    while( scanf("%d" , &n ) != EOF ) {
        if( n == 0 ) break ;
        cas += 1 ;

        for( int i = 0 ; i < n ; i++ ) scanf("%d" , &a[i] ) ;
        for( int i = 0 ; i < n ; i++ ) scanf("%d" , &b[i] ) ;

        int ans = F(0 , 0) ;
        printf("%d\n" , ans ) ;
    }

    return 0 ;
}
