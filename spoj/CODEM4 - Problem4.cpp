#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 50 + 10 ;
const int inf = (int) 2e9 ;

long long arr[N] , dp1[N][N][2] , dp2[N][N][2] ;
int n ;

long long F(int i , int j , int t) {
    if( i > j ) return 0 ;

    long long &ret = dp1[i][j][t] ;
    if( ret != -1 ) return ret ;

    if( t == 0 ) {
        ret = arr[i] + F(i + 1 , j , 1 - t) ;
        ret = max(ret , arr[j] + F(i , j - 1 , 1 - t)) ;
    }
    else {
        ret = F(i + 1 , j , 1 - t) ;
        ret = min(ret , F(i , j - 1 , 1 - t)) ;
    }

    return ret ;
}

long long G(int i , int j , int t) {
    if( i > j ) return 0 ;

    long long &ret = dp2[i][j][t] ;
    if( ret != -1 ) return ret ;

    if( t == 0 ) {
        ret = arr[i] + G(i + 1 , j , 1 - t) ;
        ret = max(ret , arr[j] + G(i , j - 1 , 1 - t)) ;
    }
    else {
        ret = G(i + 1 , j , 1 - t) ;
        ret = max(ret , G(i , j - 1 , 1 - t)) ;
    }

    return ret ;
}

int main(){
//    freopen("in.txt" , "r" , stdin ) ;
    int T ; scanf("%d" , &T ) ;
    while( T-- ) {
        memset(dp1 , -1 , sizeof(dp1)) ;
        memset(dp2 , -1 , sizeof(dp2)) ;

        scanf("%d", &n ) ;
        for( int i = 1 ; i <= n ; i++ ) {
            scanf("%lld" , &arr[i] ) ;
        }

        long long smart = F(1 , n , 0) ;
        long long dumb = G(1 , n , 0) ;

        printf("%lld %lld\n" , dumb , smart) ;
    }
    return 0 ;
}

