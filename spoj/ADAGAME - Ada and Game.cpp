#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

int dp[10005][105] , cas = 0 , moves ;

int nxt( int r ) {
    if( r == 9 ) return 0 ;
    return r + 1 ;
}

int F( int n , int step ) {
    if( step > moves ) return n ;
    int &ret = dp[n][step] ;
    if( ret != -1 ) return ret ;
    ret = (step&1) ? -inf : inf ;
    int num[4] ; int tmp = n ;
    for( int i = 0 ; i < 4 ; i++ ) {
        num[4 - i - 1] = tmp % 10 ;
        tmp /= 10 ;
    }
    for( int i = 0 ; i < 4 ; i++ ) {
        tmp = 0 ;
        for( int j = 0 ; j < 4 ; j++ ) {
            if( i == j ) tmp = tmp * 10 + nxt( num[j] ) ;
            else tmp = tmp * 10 + num[j] ;
        }
        if( step & 1 ) {
            ret = max(ret , F(tmp , step + 1)) ;
        }else {
            ret = min(ret , F(tmp , step + 1)) ;
        }
    }
    return ret ;
}

int main(){
//    freopen("in.txt" , "r" , stdin ) ;
    int T ; scanf("%d" , &T ) ;
    while( T-- ) {
        string s ; cin >> s >> moves ;
        int n = 0 ;
        for( int i = 0 ; i < (int) s.size() ; i++ ) {
            n = n * 10 + (s[i] - '0') ;
        }
        memset( dp , -1 , sizeof(dp) ) ;
        int ans = F(n , 1) ;
        if( ans > n ) printf("Ada\n") ;
        else printf("Vinit\n") ;
    }
    return 0 ;
}
