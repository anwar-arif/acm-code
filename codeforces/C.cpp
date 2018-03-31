#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 300 + 10 ;
const int inf = (int) 2e9 ;

int arr[N][N] , dp[N][N] ;
int r , c , k ;

void DP() {
    memset( dp , 0 , sizeof(dp)) ;
    for( int i = 1 ; i <= r ; i++ ) {
        for( int j = 1 ; j <= c ; j++ ) {
            if( i == 1 ) dp[i][j] = dp[i][j - 1] + ( arr[i][j] == 1 ) ;
            else if( j == 1 ) dp[i][j] = dp[i - 1][j] + ( arr[i][j] == 1 ) ;
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (arr[i][j] == 1) ;
            }
        }
    }
}

void cal() {
    int mx = -1 , x1 , x2 , y1 , y2 ;
    for( int i = k ; i <= r ; i++ ) {
        for( int j = k ; j <= c ; j++ ) {
            int nw = dp[i][j] ;
            nw -= ( dp[i - k][j] + dp[i][j - k] ) ;
            nw += dp[i - k][j - k] ;
            if( nw > mx ) {
                mx = nw ;
                x1 = i - k + 1 ;
                x2 = i ;
                y1 = j - k + 1 ;
                y2 = j ;
            }
        }
    }
    for( int i = x1 ; i <= x2 ; i++ ) {
        for( int j = y1 ; j <= y2 ; j++ ) {
            arr[i][j] = 0 ;
        }
    }
}

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    scanf("%d %d %d" , &r , &c , &k ) ;
    for( int i = 1 ; i <= r ; i++ ) {
        for( int j = 1 ; j <= c ; j++ ) {
            scanf("%d" , &arr[i][j] ) ;
        }
    }
    DP() ; cal() ;
    DP() ; cal() ;
    int ans = 0 ;
    for( int i = 1 ; i <= r ; i++ ) {
        for( int j = 1 ; j <= c ; j++ ) {
            ans += ( arr[i][j] == 0 ) ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}
