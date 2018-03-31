#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 17 ;
const int inf = (int) 2e9 ;

int check( int n , int pos ) { return ( n & ( 1 << pos ) ) ;}
int on( int n , int pos ) { return ( n | ( 1 << pos ) ) ; }

char str[N] ;
int arr[N] ;
long long dp[(1 << N)][21] ;
int b , k , len ;

long long rec( int mask , int md ) {
    if( mask == (1 << len) - 1 ) {
        return md == 0 ;
    }
    long long &ret = dp[mask][md] ;
    if( ret != -1 ) return ret ;
    ret = 0 ;
    for( int i = len - 1 ; i >= 0 ; i-- ) {
        if( check( mask , i ) == 0 ) {
            ret += rec( on( mask , i ) , (md*b + arr[i]) % k ) ;
        }
    }
    return ret ;
}

int main() {
    int tst , cas = 0 ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        scanf("%d %d" , &b , &k ) ;
        scanf(" %s" , &str ) ;
        len = strlen( str ) ;
        for( int i = 0 ; i < len ; i++ ) {
            if( isalpha(str[i])) arr[i] = ( str[i] - 'A' ) + 10 ;
            else arr[i] = ( str[i] - '0' ) ;
        }
        memset( dp , -1 , sizeof(dp)) ;
        printf("Case %d: %lld\n" , ++cas , rec( 0 , 0 ) ) ;
    }
    return 0 ;
}

