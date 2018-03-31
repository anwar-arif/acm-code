#include<bits/stdc++.h>
using namespace std ;

const int N = 100 + 10 ;
const int M = 10000 + 10 ;

int n , dp[N][M] , weight[N] , cost[N] , CAP ;

int F(int i , int w) {
    if(i == n + 1) return 0 ;
    int &ret = dp[i][w] ;
    if(ret != -1) return ret ;
    int p1 = 0 , p2 = 0 ;
    if(w + weight[i] <= CAP) {
        p1 = cost[i] + F(i + 1 , w + weight[i]) ;
    }
    p2 = F(i + 1 , w) ;
    return ret = max(p1 , p2) ;
}

int main() {
    memset(dp , -1 , sizeof(dp) ) ;
    scanf("%d %d" , &n , &CAP) ;
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d %d" , &weight[i] , &cost[i] ) ;
    }
    printf("%d\n" , F(1 , 0) ) ;
    return 0 ;
}
///Complexity : O(n*cap) ; n = number of things. cap = capacity
