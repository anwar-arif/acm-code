#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

char s[N] ;

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    int q ; scanf("%d" , &q ) ;
    while( q-- ) {
        int n ; scanf("%d" , &n ) ;
        scanf("%s" , &s ) ;
        if( n == 2 ) {
            if( s[0] >= s[1] ) printf("NO\n") ;
            else {
                printf("YES\n") ;
                printf("2\n%c %c\n" , s[0] , s[1] ) ;
            }
        } else {
            printf("YES\n") ;
            printf("2\n") ;
            printf("%c " , s[0] ) ;
            for( int i = 1 ; i < n ; i++ ) printf("%c" , s[i] ) ;
            printf("\n") ;
        }
    }
    return 0 ;
}
