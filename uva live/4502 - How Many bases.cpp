#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 1e5 + 10 ;
const int inf = (int) 2e9 ;
const long long mod = (long long) 100000007 ;

int primes[N] , P[N] , tot = 0 ;
long long n , m , T ;

void sieve() {
    for( int i = 0 ; i < N ; i++ ) P[i] = 1 ;
    for( int i = 2 ; i < N ; i++ ) {
        if( P[i] == 1 ) {
            for( int j = i + i ; j < N ; j += i ) {
                P[j] = 0 ;
            }
        }
    }
    primes[++tot] = 2 ;
    for( int i = 3 ; i < N ; i += 2 ) {
        if( P[i] == 1 ) primes[++tot] = i ;
    }
}

long long cnt[N] ;
int len = 0 ;

void factorize( long long nn ) {
    for( int i = 1 ; primes[i] * primes[i] <= nn ; i++ ) {
        if( nn % primes[i] == 0 ) {
            long long nw = 0 ;
            while( nn % primes[i] == 0 ) {
                nn /= primes[i] ; ++nw ;
            }
            cnt[++len] = ( nw * m ) ;
        }
    }
    if( nn > 1 ) {
        cnt[++len] = (1LL * m) ;
    }
}

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    sieve() ; int cas = 0 ;
    while( scanf("%lld %lld %lld" , &n , &m , &T) != EOF ) {
        if( n + m + T == 0 ) break ;
        len = 0 ;
        factorize( n ) ;
        long long x = 1 , y = 1 ;
        for( int i = 1 ; i <= len ; i++ ) {
            x = (x * ( (cnt[i] / T) + 1) ) % mod ;
            y = (y * ( (cnt[i] / (T + 1) ) + 1 ) ) % mod ;
        }
        long long ans = ( x - y ) % mod ;
        ans += mod ;
        ans %= mod ;
        printf("Case %d: %lld\n" , ++cas , ans ) ;
    }
    return 0 ;
}
