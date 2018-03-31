#include<bits/stdc++.h>
using namespace std ;

int main() {
    int tst , cas = 0 , t , d ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        scanf("%d %d" , &t , &d ) ;
        printf("Case %d: %0.9f\n" , ++cas , (t&1) ? 0 : ( 1.0 / ((double)t + 1.0)) ) ;
    }
    return 0 ;
}
