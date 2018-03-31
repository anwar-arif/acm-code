#include<bits/stdc++.h>
using namespace std ;

const int N = (int)1e5 + 10 ;
const int inf = (int)1e7 ;

vector<int>g[N] ;
int level[N] ;
int par[N][25] ;
int t[N] ;
int n;

/** LCA start */
void dfs0( int u , int p , int d ) {
    int len = (int)g[u].size() ;
    level[u] = d ;
    for( int i = 0 ;i < len ; i++ ) {
        int v = g[u][i] ;
        if( v != p ) {
            t[v] = u ;
            dfs0( v , u , d+1 ) ;
        }
    }
}

void ith_parent(){
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 0 ; j <= 20 ; j++ ) {
            par[i][j] = -1 ;
        }
    }
    for( int i = 1 ; i<= n ; i++) {
        par[i][0] = t[i] ;
    }
    for( int j = 1 ; j <= 20 ; j++ ) {
        for( int i = 1 ; i <= n ; i++ ) {
            if( par[i][j-1] != -1 ) {
                par[i][j] = par[ par[i][j-1] ][j-1] ;
            }
        }
    }
}

int lca( int p , int q ) {
    if( level[p] < level[q] ) {
        swap( p , q ) ;
    }
    for( int i = 20 ; i >= 0 ; i-- ) {
        if( level[p] - ( 1 << i ) >= level[q] ) {
            p = par[p][i] ;
        }
    }
    if( p == q ) return p ;
    for( int i = 20 ; i >= 0 ; i-- ) {
        if( par[p][i] !=-1 && par[p][i] != par[q][i] ) {
            p = par[p][i] ;
            q = par[q][i] ;
        }
    }
    return t[p] ;
}

int dist( int u , int v ) {
    return ( level[u] + level[v] - ( 2 * level[ lca(u, v) ] ) ) ;
}

void Prepare_lca( int root ) {
    t[root] = root ;
    dfs0( root , root , 0 ) ;
    ith_parent();
}

/** LCA end */
/** Decomposition start*/
bool dead[N] ;
int tot ;
int sub[N] ;
int parent[N] ;

int dfs1( int u , int pre ) {
    sub[u] = 1 ;
    ++tot;
    int len = (int)g[u].size() ;
    for( int i = 0; i < len ; i++ ) {
        int v = g[u][i] ;
        if(v == pre || dead[v] ) continue ;
        sub[u] += dfs1( v , u ) ;
    }
    return sub[u] ;
}

int get_centroid( int u , int pre ) {
    int len = (int)g[u].size() ;
    for( int i = 0; i < len ; i++ ) {
        int v = g[u][i];
        if(v == pre || dead[v] ) continue;
        if( sub[v] > ( tot/2 ) ) {
            return get_centroid( v , u ) ;
        }
    }
    return u;
}

void Decomposition( int root , int pre ) {
    tot = 0 ;
    dfs1( root , -1 ) ;

    int centroid = get_centroid( root , -1 ) ;

    if( pre == -1 ) pre = centroid ;
    parent[centroid] = pre ;

    dead[centroid] = 1 ;

    int len = (int)g[centroid].size() ;

    for( int i = 0; i < len ; i++ ) {
        int v = g[centroid][i] ;
        if( dead[v] ) continue ;
        Decomposition( v , centroid ) ;
    }
}

/**Decomposition end*/

struct data{
    int node , dst ;
    data(){}
    data( int _node , int _dst ) {
        node = _node ;
        dst = _dst ;
    }
    bool operator < ( const data &p ) const {
        return dst > p.dst ;
    }
};

priority_queue< data > pq[N] ;
bool black[N] ;

///if white , update
void update( int u ) {
    int cur = u ;
    while( 1 ) {
        pq[cur].push( data( u , dist( u , cur ) ) ) ;
        if( cur == parent[cur] )break ;
        cur = parent[cur] ;
    }
}

int query( int u ) {
    int cur = u ;
    int ret = inf ;
    data nw ;
    while( 1 ) {
        while( 1 ) {
            nw = pq[cur].top() ;
            if( black[nw.node] ) pq[cur].pop() ;
            else break ;
        }
        ret = min( ret , dist( u , cur ) + nw.dst ) ;
        if( cur == parent[cur] ) break ;
        cur = parent[cur] ;
    }
    return ret ;
}

int main() {
//    freopen("input.txt" , "r" , stdin ) ;
    int u , v , q , typ ;
    scanf("%d" , &n ) ;
    for( int i = 1 ; i < n ; i++ ) {
        scanf("%d %d" , &u , &v ) ;
        g[u].push_back( v ) ;
        g[v].push_back( u ) ;
    }
    for( int i = 0 ; i <= n ; i++ ) {
        dead[i] = 0 ;
        black[i] = true ;
    }
    black[0] = false ;

    Prepare_lca( 1 ) ;
    Decomposition( 1 , -1 ) ;

    for( int i = 1 ; i <= n ; i++ ) {
        pq[i].push( data( 0 , inf ) ) ;
    }

    scanf("%d" , &q ) ;
    while( q-- ) {
        scanf("%d %d" , &typ , &u ) ;
        if( typ == 0 ) {
            black[u] = !black[u] ;
            if( !black[u] ) {
                update( u ) ;
            }
        }
        else{
            int ans = query( u ) ;
            printf("%d\n" , ans >= inf ? -1 : ans ) ;
        }
    }
}
