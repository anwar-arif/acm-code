#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

stack< int > stk ;
int arr[N] , r , c ;
char str[N] ;

int histogram() {
    int area = 0 , mx_area = 0 ;
    while( !stk.empty() ) stk.pop() ;
    int i , top ;
    for( i = 1 ; i <= c ; ) {
        if( stk.empty() || arr[ stk.top() ] <= arr[i] ) {
            stk.push( i++ ) ;
        }
        else {
            top = stk.top() ; stk.pop() ;
            if( stk.empty() ) {
                area = arr[top] * (i - 1) ;
            }
            else {
                area = arr[top] * (i - stk.top() - 1) ;
            }
            mx_area = max( mx_area , area ) ;
        }
    }
    while( !stk.empty() ) {
        top = stk.top() ; stk.pop() ;
        if( stk.empty() ) area = arr[top] * (i - 1) ;
        else area = arr[top] * (i - stk.top() - 1) ;
        mx_area = max(mx_area , area) ;
    }
    return mx_area ;
}
/*Uses 1-indexed array*/
int main() {
    int tst , cas = 0 ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        memset( arr , 0 , sizeof(arr) ) ;
        scanf("%d %d" , &r , &c ) ;
        int mx = 0 ;
        for( int i = 0 ; i < r ; i++ ) {
            scanf("%s" , str+1 ) ;
            for( int j = 1 ; j <= c ; j++ ) {
                if( str[j] == '0' ) arr[j] = 0 ;
                else arr[j] += 1 ;
            }
            mx = max( mx , histogram() ) ;
        }
        printf("Case %d: %d\n" , ++cas , mx) ;
    }
    return 0 ;
}
