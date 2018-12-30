#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

set< long long > s ;

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    int n , k ; cin >> n ;
    for( int k = 1 ; k <= n ; k++ ) {
        long long sum = 0 ;
        for( int i = 0 ; ; i += k ) {
            if( i % n == 0 ) {
                break ;
            }
            sum += (i % n) + 1 ;
        }
        s.insert(sum) ;
    }
    for( auto it : sum ) {
        cout << *it << endl ;
    }
    return 0 ;
}
