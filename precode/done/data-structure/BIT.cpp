#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

struct fenwick {
private:
	int *t , sz ;

public:
    fenwick( int _sz = 200000 ) {
    	sz = _sz ;
    	t = new int [sz + 10] ;
    	memset( t , 0 , sizeof (t) ) ;
	}
    /*point update : set arr[x] = val*/
	void update( int x , int val ) {
		for( int i = x ; i <= sz ; i += i & (-i)) {
			t[i] += val;
		}
	}

	int query( int x ) {
		int sum = 0 ;
		for( int i = x ; i > 0 ; i -= i & (-i) ) {
			sum += t[i] ;
		}
		return sum ;
	}
    /*range query : prefix_sum(r) - prefix_sum(l - 1)*/
	int query( int l , int r ) {
		if( l > r ) return 0 ;
		return query(r) - query(l - 1);
	}
};

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    fenwick T ;
    fenwick S(100) ;
    S.update(5 , 15);
    cout << S.query(5) << endl ;
    return 0 ;
}
