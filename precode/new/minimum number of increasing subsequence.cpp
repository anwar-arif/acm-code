#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 ;

///minimum number of increasing subsequences
///is equal to the length of the longest decreasing subsequence

int arr[N] ;
///code of longest decreasing subsequence

multiset<int>st ;

int main() {
    int n ;
    scanf("%d" , &n ) ;
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d" , &arr[i] ) ;
    }
    sort( arr+1 , arr+1+n ) ;
    for( int i = n ; i >= 1 ; i-- ) {
        multiset<int>::iterator it = st.lower_bound( arr[i] + 1 ) ;
        if( it != st.end() ) {
            st.erase( it ) ;
        }
        st.insert( arr[i] ) ;
    }
    int ans = (int)st.size() ;
    cout << ans << endl ;
}
///complexity O(n*log(n))
/*
4
1 1 3 4
*/
