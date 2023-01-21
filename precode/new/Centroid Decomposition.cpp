#include<bits/stdc++.h>
using namespace std ;

const int N = (int)1e5 + 10 ;
const int inf = (int)1e8 ;
const int LOG = 20 ;

vector<int>adj[N] ;
int level[N] ; /// level of a node in tree
int par[N][LOG+5] ; /// lca parent table
int t[N] ; /// immediate parent of a node
int n; /// total nodes in tree

/**
*  calculate immediate parent and level of a node
*/
void dfs0( int u , int p , int d ) {
    int len = (int)adj[u].size() ;
    level[u] = d ;
    for( int i = 0 ;i < len ; i++ ) {
        int v = adj[u][i] ;
        if( v != p ) {
            t[v] = u ;
            dfs0( v , u , d+1 ) ;
        }
    }
}

/**
*   Prepare Pharse Table for LCA
*/
void ith_parent(){
    for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 0 ; j <= LOG ; j++ ) {
            par[i][j] = -1 ;
        }
    }
    for( int i = 1 ; i<= n ; i++) {
        par[i][0] = t[i] ;
    }
    for( int j = 1 ; j <= LOG ; j++ ) {
        for( int i = 1 ; i <= n ; i++ ) {
            if( par[i][j-1] != -1 ) {
                par[i][j] = par[ par[i][j-1] ][j-1] ;
                ///as 2^(x-1) + 2^(x-1) = 2^x
            }
        }
    }
}

/**
*   return LCA of node u and v
*/
int lca( int p , int q ) {
    if( level[p] < level[q] ) {
        swap( p , q ) ;
    }
    for( int i = LOG ; i >= 0 ; i-- ) {
        if( level[p] - ( 1 << i ) >= level[q] ) {
            p = par[p][i] ;
        }
    }
    if( p == q ) return p ;
    for( int i = LOG ; i >= 0 ; i-- ) {
        if( par[p][i] !=-1 && par[p][i] != par[q][i] ) {
            p = par[p][i] ;
            q = par[q][i] ;
        }
    }
    return t[p] ;
}

/**
* return distance between node u to v
*/
int dist( int u , int v ) {
    return ( level[u] + level[v] - ( 2 * level[ lca(u, v) ] ) ) ;
}

void Prepare_lca( int root ) {
    t[root] = root ;
    dfs0( root , root , 0 ) ;
    ith_parent();
}

/// Decomposition Part
bool dead[N] ; /// It'll track whether a node is decomposed or not
int tot ; /// total number of node in the current Tree
int sub[N] ; /// size of sub tree
int parent[N] ; /// parent of a node in centroid tree

/**
*   It will calculate sub tree size of each node
*/
int dfs1( int u , int pre ) {
    sub[u] = 1 ;
    ++tot; /// calculating the size of current tree
    int len = (int)adj[u].size() ;
    for( int i = 0; i < len ; i++ ) {
        int v = adj[u][i] ;
        if(v == pre || dead[v] ) continue ;
        sub[u] += dfs1( v , u ) ;
    }
    return sub[u] ;
}
/**
*   It will return the Centroid of current tree
*/
int get_centroid( int u , int pre ) {
    int len = (int)adj[u].size() ;
    for( int i = 0; i < len ; i++ ) {
        int v = adj[u][i];
        if(v == pre || dead[v] ) continue;
        if( sub[v] > ( tot/2 ) ) {
            return get_centroid( v , u ) ;
        }
    }
    return u;
}
/**
*   It will decompose the current tree
*/
void Decomposition( int root , int pre ) {
    tot = 0 ;
    dfs1( root , -1 ) ;

    int centroid = get_centroid( root , -1 ) ;  /// centroid of current tree

    if( pre == -1 ) pre = centroid ;
    parent[centroid] = pre ;  /// Adding edge in the Centroid tree

    dead[centroid] = 1 ;  /// current centroid is removed from the tree

    int len = (int)adj[centroid].size() ;

    for( int i = 0; i < len ; i++ ) {
        int v = adj[centroid][i] ;
        if( dead[v] ) continue ; /// checking adjacent node is already removed or not
        Decomposition( v , centroid ) ;
    }
}

int ans[N] ; /// distance to closest red colored node

///update color to red and update distance
///O(logn)
void update( int u ) {
    int cur = u ;
    while( 1 ) {
        ans[cur] = min( ans[cur] , dist( u , cur ) ) ;
        if( cur == parent[cur] ) break ;
        cur = parent[cur] ;
    }
}

///return distance to closest red colored node from u
///O(logn)
int query( int u ) {
    int ret = inf ;
    int cur = u ;
    while( 1 ) {
        ret = min( ret , dist( u , cur ) + ans[cur] ) ;
        if( cur == parent[cur] ) break ;
        cur = parent[cur] ;
    }
    return ret ;
}

int main() {
    /// nodes are 1....n
    int u , v , q , typ ;
    scanf("%d %d" , &n , &q  ) ;
    for( int i = 1 ; i < n ; i++ ) {
        scanf("%d %d" , &u , &v ) ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }
    for( int i = 0 ; i <= n ; i++ ) {
        dead[i] = 0 ;
    }
    Prepare_lca( 1 ) ;
    Decomposition( 1 , -1 ) ;
    for( int i = 0 ; i <= n ; i++ ) {
        ans[i] = inf ;
    }
    update( 1 ) ;
    while( q-- ) {
        scanf("%d %d" , &typ , &u ) ;
        if( typ == 1 ) update( u ) ;
        else{
            printf("%d\n" , query( u ) ) ;
        }
    }
}
/**
    complexity : tree has at most log(n) levels and for each level a DFS visits
                 visits at most n nodes. So, complexity to build the tree is
                 O(nlog(n)) . complexity of LCA is also O(nlog(n)) .
*/

