#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

int k , n , tot = 0 ;
long long v[N] , arr[N] ;
char s[N] ;

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    long long answer = 0 ;
    scanf("%d %d" , &n , &k) ;
    for( int i = 0 ; i < n ; i++ ) scanf("%lld" , &v[i] ) ;
    scanf("%s" , &s ) ;
    for( int i = 0 ; i < n ; i++ ) {
        int j = i ;
        while( j + 1 < n && s[j + 1] == s[i] ) j += 1 ;
        tot = 0 ;
        for( int cur = i ; cur <= j ; cur++ ) {
            arr[++tot] = v[cur] ;
        }
        sort(arr + 1 , arr + 1 + tot) ;
        reverse(arr + 1 , arr + 1 + tot) ;
        int cnt = 0 ;
        for( int cur = 1 ; cur <= tot ; cur++ ) {
            answer += arr[cur] ;
            ++cnt ;
            if( cnt == k ) break ;
        }
        i = j ;
    }
    printf("%lld\n" , answer ) ;
    return 0 ;
}
