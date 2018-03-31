#include<bits/stdc++.h>
using namespace std ;

const int N = 100000 + 10 ;

typedef long long ll ;

ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

ll phi( ll n ) {
    ll ret = n;
    for(int i = 2; i * i <= n;i++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            ret -= ret / i;
        }
    }
    if( n > 1 )ret -= ret/n;
    return ret;
}

int main() {
//    freopen("A-large.in" , "r" , stdin ) ;
//    freopen("output.txt" , "w" , stdout ) ;
    int tst , cas = 0 ;
    long long a , n , mod ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        scanf("%lld %lld %lld" , &a , &n , &mod ) ;
        long long p = phi( mod ) ;
        long long nw = 1LL ;
        for( int i = 1 ; i <= n ; i++ ) {
            nw *= i ;
            nw %= p ;
        }
        long long ans = bigmod( a , nw + p , mod ) ;
        printf("Case #%d: %lld\n", ++cas , ans ) ;
    }
    return 0 ;
}
