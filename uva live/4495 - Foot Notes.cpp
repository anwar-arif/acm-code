#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 500 + 10 ;
const int M = (int) 100 + 10 ;
const int inf = (int) 2e9 ;

int dp[N] , vis[N][M] ;
int n , s , w , cas = 0 ;
vector< int > arr[N] ;

int F(int pos) {
    if( pos > n ) return 0 ;
    int &ret = dp[pos] ;
    if( ret != -1 ) return ret ;
    ret = inf ;
    set< int > unq ;
    for( int i = pos ; i <= n ; i++ ) {
        for( int x : arr[i] ) {
            unq.insert(x) ;
        }
        int tot = unq.size() ;
        if(tot + i - pos + 1 <= s) ret = min( ret , tot + F(i + 1) ) ;
        else break ;
    }
    return ret ;
}


int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    int tst ; scanf("%d" , &tst ) ;
    while( tst-- ) {
        ++cas ; memset(dp , -1 , sizeof(dp)) ;
        scanf("%d %d %d" , &n , &s , &w ) ;
        for( int i = 0 ; i <= n ; i++ ) arr[i].clear() ;
        for( int i = 1 ; i <= w ; i++ ) {
            int k ; scanf("%d" , &k ) ;
            for( int j = 1 ; j <= k ; j++ ) {
                int x ; scanf("%d" , &x ) ;
                arr[x].push_back(i) ;
            }
        }
        int ans = F(1) ;
        printf("Case %d: %d\n" , cas , ans == inf ? -1 : ans ) ;
    }
    return 0 ;
}
