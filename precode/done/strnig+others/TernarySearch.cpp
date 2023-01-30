#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

int arr[N] ;

int ternary_search( int l , int r , int x ) {
    while( r >= l ) {
        int mid1 = l + (r - l) / 3 ;
        int mid2 = r - (r - l) / 3 ;
        if( arr[mid1] == x ) return mid1 ;
        if( arr[mid2] == x ) return mid2 ;
        if( x < arr[mid1] ) {
            r = mid1 ;
        }
        else if( x > arr[mid2] ) {
            l = mid2 ;
        }
        else {
            l = mid1 , r = mid2 ;
        }
    }
    return -1 ;
}

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    int n ; scanf("%d" , &n ) ;
    for( int i = 1 ; i <= n ; i++ ) scanf("%d" , &arr[i] ) ;
    sort( arr+1 , arr+1+n ) ;
    int indx = ternary_search(1 , n , 5) ;
    cout << indx << endl ;
    return 0 ;
}
