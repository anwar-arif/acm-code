#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

char str[10] ;
int dp[10][270][270] , vis[10][270][270] , cas = 0 ;
int r , c , msk[10] ;

int F( int pos , int cur , int pre ) {
    if( pos >= r ) {
        return (pre == (1 << c) - 1) ? 0 : inf ;
    }

    int &v = vis[pos][cur][pre] ;
    int &ret = dp[pos][cur][pre] ;

    if( v == cas ) return ret ;
    v = cas ;

    ret = inf ;
    for( int m = 0 ; m < (1 << c) ; m++ ) {
        int cnt = 0 ;
        int row[3] = {pre , cur , msk[pos + 1]} ;

        for( int j = 0 ; j < c ; j++ ) {
            if( !(m & (1 << j)) ) continue ;
            cnt += 1 ;

            for( int k = 0 ; k < 3 ; k++ ) row[k] ^= (1 << j) ;
            if( j + 1 < c ) {
                for( int k = 0 ; k < 3 ; k++ ) row[k] ^= (1 << (j + 1)) ;
            }
            if( j - 1 >= 0 ) {
                for( int k = 0 ; k < 3 ; k++ ) row[k] ^= (1 << (j - 1)) ;
            }
        }

        if( pos == 0 ) ret = min( ret , cnt + F(pos + 1 , row[2] , row[1]) ) ;
        else if( row[0] == (1 << c) - 1 ) {
            ret = min( ret , cnt + F( pos + 1 , row[2] , row[1] ) ) ;
        }
    }

    return ret ;
}

int main(){
    memset(vis , 0 , sizeof(vis)) ;
    int T ; scanf("%d" , &T ) ;
    while( T-- ) {
        cas += 1 ;
        scanf("%d %d" , &r , &c ) ;
        memset( msk , 0 , sizeof(msk) ) ;

        for( int t = 0 ; t < r ; t++ ) {
            scanf("%s" , &str ) ;
            int mask = 0 ;
            for( int i = 0 ; i < c ; i++ ) {
                if( str[i] == '*' ) mask = (mask | (1 << i)) ;
            }
            msk[t] = mask ;
        }

        int ans = F(0 , msk[0] , 0) ;
        printf("Case %d: ", cas ) ;

        if( ans == inf ) printf("impossible\n") ;
        else printf("%d\n", ans ) ;
    }
    return 0 ;
}
