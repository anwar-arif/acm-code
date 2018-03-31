#include<bits/stdc++.h>
using namespace std;

const int N = (int) 3000 + 10 ;
const int M = 500000 + 10 ;

int arr[N] ;
int dp[2][M] , n ;

int cal() {
    dp[0][0] = 0 ;
    int now = 1 , pre = 0 ;
    for( int i = 0 ; i < n ; i++ ) {
        for( int j = 0 ; j < M ; j++ ) {
            if( dp[pre][j] == -1 ) continue ;

            dp[now][j] = max( dp[now][j] , dp[pre][j] ) ;

            int diff = abs( j - arr[i] ) ;
            dp[now][diff] = max( dp[now][diff] , max( dp[pre][diff] , dp[pre][j] + arr[i] ) ) ;

            diff = j + arr[i] ;
            dp[now][diff] = max( dp[now][diff] , max( dp[pre][diff] , dp[pre][j] + arr[i] ) ) ;
        }
        swap(now , pre) ;
    }
    return max( dp[now][0] , dp[pre][0] ) ;
}

int main() {
    int tst , cas = 0 ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        scanf("%d" , &n ) ;
        for( int i = 0 ; i < n ; i++ ) scanf("%d" , &arr[i] ) ;
        memset( dp , -1 , sizeof(dp)) ;
        printf("Case %d: " , ++cas ) ;
        int ans = cal() ;
        if( ans <= 0 ) printf("impossible\n") ;
        else printf("%d\n" , ans/2 ) ;
    }
    return 0 ;
}

