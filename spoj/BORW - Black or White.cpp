#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 200 + 10 ;
const int inf = (int) 2e9 ;

int vis[N][N][N] , cas = 0 ;
int dp[N][N][N] , arr[N] , n ;

int F( int i , int b , int w ) {
    if( i > n + 1 ) return 0 ;

    int &v = vis[i][b][w] ;
    int &ret = dp[i][b][w] ;

    if( v == cas ) return ret ;
    v = cas ;

    ret = inf ;
    ret = min( ret , 1 + F(i + 1 , b , w) ) ;
    if( arr[i] > arr[b] ) ret = min( ret , F(i + 1 , i , w) ) ;
    if( arr[i] < arr[w] ) ret = min( ret , F(i + 1 , b , i) ) ;

    return ret ;
}

int main(){
//    freopen("in.txt" , "r" , stdin ) ;
    memset( vis , 0 , sizeof(vis) ) ;
    while( scanf("%d" , &n ) != EOF ) {
        if( n == -1 ) break ;
        cas += 1 ;

        arr[0] = -1 , arr[1] = inf ;

        for( int i = 2 ; i <= n + 1 ; i++ ) {
            scanf("%d" , &arr[i] ) ;
        }

        int ans = F( 2 , 0 , 1 ) ;
        printf("%d\n" , ans ) ;
    }
    return 0 ;
}
