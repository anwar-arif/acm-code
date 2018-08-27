#include<bits/stdc++.h>
using namespace std ;

const int N = 30 ;
const int M = 500 ;

unsigned long long dp[N + 10][M + 10] , P[N + 10] ;
int n , s , T , cas = 0 , vis[N + 10][M + 10] ;

void PreProcess() {
    P[0] = 1 ;
    for( int i = 1 ; i <= N ; i++ ) {
        P[i] = P[i - 1] * 6 ;
    }
}

unsigned long long F( int pos , int sum ) {
    if( pos > n ) {
        return ( sum >= s ) ? 1 : 0 ;
    }
    int &v = vis[pos][sum] ;
    unsigned long long &ret = dp[pos][sum] ;

    if( v == cas ) return ret ;
    v = cas ;

    ret = 0 ;
    for( int i = 1 ; i <= 6 ; i++ ) ret += F(pos + 1 , sum + i ) ;

    return ret ;
}

int main() {
    PreProcess() ;
    memset( vis , 0 , sizeof(vis) ) ;
    scanf("%d" , &T ) ;
    while( T-- ) {
        scanf("%d %d" , &n , &s ) ;
        cas += 1 ;

        unsigned long long up = F(1 , 0) ;
        unsigned long long down = P[n] ;
        unsigned long long g = __gcd( up , down ) ;

        up /= g , down /= g ;

        printf("Case %d: " , cas ) ;
        if( down == 1 ) printf("%llu\n" , up ) ;
        else printf("%llu/%llu\n" , up , down ) ;
    }
    return 0 ;
}
