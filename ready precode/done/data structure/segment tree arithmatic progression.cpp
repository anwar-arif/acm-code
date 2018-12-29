/*segment tree with arithmatic progression update*/
#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

///starting value of AP for each node is start[] with diff. diff[]
long long sum[3 * N] , start[3 * N] , diff[3 * N] ;
int n , q ;

long long kth_term( long long K , long long A , long long D ) {
    return (A + (K - 1) * D) ;
}

///find sum of k terms with first value A and difference D
long long get_sum(long long K , long long A , long long D) {
    long long B = kth_term(K , A , D) ;
    return (K * (A + B)) / 2LL ;
}

void push_down(int node , int lft , int rt , int b , int e ) {
    if( start[node] == 0 || diff[node] == 0 ) return ;
    if( b != e ) {
        int mid = (b + e) / 2 ;

        long long total = (long long) e - b + 1 ;
        long long lftsz = (mid - b + 1) ;

        sum[lft] += get_sum(lftsz , start[node] , diff[node]) ;
        start[lft] += start[node] ;
        diff[lft] += diff[node] ;

        long long kth = kth_term(lftsz + 1 , start[node] , diff[node]) ;
        sum[rt] += get_sum(total - lftsz , kth , diff[node]) ;
        start[rt] += kth ;
        diff[rt] += diff[node] ;
    }
    start[node] = 0 , diff[node] = 0 ;
}

long long query( int node , int b , int e , int i , int j ) {
    if( e < i || b > j ) return 0 ;

    int lft = 2 * node , rt = lft + 1 , mid = (b + e) / 2 ;
    push_down(node , lft , rt , b , e) ;

    if( b >= i && e <= j ) return sum[node] ;

    return (query(lft , b , mid , i , j) + query(rt , mid + 1 , e , i , j)) ;
}

void upd( int node , int b , int e , int i , int j , long long A , long long D ) {
    if( e < i || b > j ) return ;

    int lft = 2 * node , rt = lft + 1 , mid = (b + e) / 2 ;
    push_down(node , lft , rt , b , e) ;

    if( b >= i && e <= j ) {
        long long sz = (long long) e - b + 1 ;
        sum[node] += get_sum(sz , A , D) ;
        start[node] += A ;
        diff[node] += D ;
        return ;
    }

    if( i <= mid ) {
        long long lftsz = (mid - i + 1) ;
        long long kth = kth_term(lftsz + 1 , A , D) ;

        upd(lft , b , mid , i , j , A , D) ;
        upd(rt , mid + 1 , e , i , j , kth , D) ;
    }
    else {
        upd(rt , mid + 1 , e , i , j , A , D) ;
    }

    sum[node] = sum[lft] + sum[rt] ;
}

void build( int node , int b , int e ) {
    memset(sum , 0 , sizeof(sum) ) ;
    memset(start , 0 , sizeof(start) ) ;
    memset(diff , 0 , sizeof(diff) ) ;
}

int main() {
//    freopen("in.txt" , "r" , stdin) ;
    scanf("%d %d" , &n , &q ) ;
    build(1 , 1 , n) ;
    while( q-- ) {
        int t ; scanf("%d" , &t ) ;
        if( t == 1 ) {
            ///first value of AP is A with difference diff
            int l , r ; long long A , diff ;
            scanf("%d %d %lld %lld" , &l , &r , &A , &diff ) ;
            upd(1 , 1 , n , l , r , A , diff) ;
        }else {
            int l , r ; scanf("%d %d" , &l , &r ) ;
            long long answer = query(1 , 1 , n , l , r) ;
            printf("%lld\n" , answer ) ;
        }
    }
    return 0 ;
}
