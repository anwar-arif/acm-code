#include<bits/stdc++.h>
using namespace std ;

int on(int n,int pos){return n=n|(1<<pos);}
int off(int n,int pos){return n = n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}

const int N = 17  ;

int dp[N][(1 << N)] , vis[N][(1 << N)] ;
int cas = 0 , n ;
int baby[N] , sol[N] ;

int rec( int pos , int mask ) {
    if( pos >= n ) return 0 ;
    int &v = vis[pos][mask] ;
    int &ret = dp[pos][mask] ;
    if( v == cas ) return ret ;
    v = cas ;
    ret = 10000000 ;
    for( int i = 0 ; i < n ; i++ ) {
        if( check( mask , i ) == 0 ) {
            int d = abs( pos - i ) + abs( baby[i] - sol[pos] ) ;
            ret = min( ret , d + rec( pos+1 , on(mask , i) ) ) ;
        }
    }
    return ret ;
}

int main() {
    memset( vis , 0 , sizeof(vis) ) ;
    while( scanf("%d" , &n ) != EOF ) {
        if( n == 0 ) break ;
        for( int i = 0 ; i < n ; i++ ) scanf("%d" , &baby[i] ) ;
        for( int i = 0 ; i < n ; i++ ) scanf("%d" , &sol[i] ) ;
        ++cas ;
        printf("%d\n" , rec( 0 , 0 ) ) ;
    }
    return 0 ;
}
