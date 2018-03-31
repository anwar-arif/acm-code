#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

int A , L , H ;

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    scanf("%d %d %d" , &A , &L , &H ) ;
    int ans = 0 ;
    for( int u = 1 ; u <= A ; u++ ) {
        for( int r = 0 ; r <= A ; r++ ) {
            int l = (u + r) * 4 ;
            int h = u + 2*r ;
            if( h != H ) continue ;
            if( l > L ) continue ;
            int rem = L - l ;
            if( rem % 2 == 1 ) continue ;
            int tot = u + r + (rem / 2) ;
            if( tot != A ) continue ;
            ans = u ;
        }
    }
    printf("%d\n" , ans ) ;
    return 0 ;
}
