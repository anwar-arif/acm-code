#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e5 + 10 ;
const int inf = (int) 2e9 ;

struct edge {
    int u , v , w ;
    edge(){}
    edge( int _u , int _v , int _w ) {
        u = _u ; v = _v ; w = _w ;
    }
    bool operator < (const edge &p ) const {
        return w < p.w ;
    }
};

vector< edge > adj ;
int par[N] ;

int findpar( int r ) {
    return ( par[r] == r ) ? r : par[r] = findpar( par[r] ) ;
}

int mst( int nodes ) {
    sort( adj.begin() , adj.end() ) ;
    for( int i = 0 ; i <= nodes ; i++ ) par[i] = i ;
    int cnt = 0 , sum = 0 ;
    int len = (int) adj.size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int u = findpar( adj[i].u ) ;
        int v = findpar( adj[i].v ) ;
        if( u != v ) {
            par[u] = v ;
            cnt += 1 ;
            sum += adj[i].w ;
            if( cnt == nodes - 1 ) break ;
        }
    }
    return sum ;
}

void init( int nodes ) {
    adj.clear() ;
}

int main() {
    int n , m ; scanf("%d %d" , &n , &m ) ;
    init( n ) ;
    for( int i = 1 ; i <= m ; i++ ) {
        int u , v , w ; scanf("%d %d %d" , &u , &v , &w ) ;
        adj.push_back( edge(u , v , w) ) ;
    }
    cout << mst(n) << endl ;
    return 0 ;
}
/*
Complexity : First sort the edges and then lenear loop of them.
             so complexity is O(ElogE) where E = number of edge;
*/
