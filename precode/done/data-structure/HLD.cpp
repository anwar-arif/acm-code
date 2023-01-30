#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 1e4 + 10 ;
const int inf = (int) 2e9 ;
const int LOG = 14 ;

int ptr = 0 , chainNo = 0 ;
vector < int > G[N] , costs[N] , indexx[N] ;
int baseArray[N] ;//stores the nodes in the order they're visited by dfs
//and seg tree uses this to build segtree
int chainInd[N] ;//chainind[u] = chainNumber which node u belongs to
int chainHead[N] ;// chainHead[chainNumber] = chainHead of chainNumber
int posInBase[N] ;//posInBase[u] = index of u in baseArray
int otherEnd[N] ;//otherEnd[edgeNumber] = node of otherEnd of edge edgeNumber
int depth[N] ;
int st[4 * N] ;
int par[N][LOG + 5] ;
int subsize[N] ;
int n ;

void build( int node , int b , int e ) {
    if( b == e ) {
        st[node] = baseArray[b] ;
        return ;
    }
    int lft = 2 * node , rt = lft + 1 , mid = (b + e) / 2 ;
    build(lft , b , mid) ;
    build(rt , mid + 1 , e) ;
    st[node] = max(st[lft] , st[rt]) ;
}

void upd( int node , int b , int e , int i , int j , int val ) {
    if( e < i || b > j ) return ;
    if( b >= i && e <= j ) {
        st[node] = val ;
        return ;
    }
    int lft = 2 * node , rt = lft + 1 , mid = (b + e) / 2 ;
    upd(lft , b , mid , i , j , val) ;
    upd(rt , mid + 1 , e , i , j , val) ;
    st[node] = max(st[lft] , st[rt]) ;
}

int query( int node , int b , int e , int i , int j ) {
    if( e < i || b > j ) return -inf ;
    if( b >= i && e <= j ) return st[node] ;
    int lft = 2 * node , rt = lft + 1 , mid = (b + e) / 2 ;
    int x = query(lft , b , mid , i , j) ;
    int y = query(rt , mid + 1 , e , i , j) ;
    return max(x , y) ;
}

/*
 * dfs used to set parent of a node, depth of a node, subtree size of a node
 */
void dfs( int u , int p , int d = 0 ) {
    depth[u] = d ;
    par[u][0] = p ;
    subsize[u] = 1 ;
    int len = (int) G[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = G[u][i] ;
        if( v == p ) continue ;
        int edge = indexx[u][i] ;
        otherEnd[edge] = v ;
        dfs(v , u , d + 1) ;
        subsize[u] += subsize[v] ;
    }
}

void prepare_lca() {
    for( int j = 1 ; j <= LOG ; j++ ) {
        for( int i = 1 ; i <= n ; i++ ) {
            if( par[i][j - 1] != -1 ) {
                par[i][j] = par[par[i][j - 1]][j - 1] ;
            }
        }
    }
}

int lca( int u , int v ) {
    if( depth[u] < depth[v] ) swap(u , v) ;
    for( int i = LOG ; i >= 0 ; i-- ) {
        if( (depth[u] - (1 << i)) >= depth[v] ) {
            u = par[u][i] ;
        }
    }
    if( u == v ) return u ;
    for( int i = LOG ; i >= 0 ; i-- ) {
        if( par[u][i] != -1 && (par[u][i] != par[v][i]) ) {
            u = par[u][i] ;
            v = par[v][i] ;
        }
    }
    return par[u][0] ;
}

/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo += 1 ensures that we are creating a new chain for each normal child.
 */
void hld( int u , int p , int cost ) {
    if( chainHead[chainNo] == -1 ) chainHead[chainNo] = u ;
    chainInd[u] = chainNo ;
    posInBase[u] = ++ptr ;
    baseArray[ptr] = cost ;
    int sc = -1 , new_cost = -1 , mx = -1 ;
    int len = (int) G[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = G[u][i] ;
        if( v == p ) continue ;
        if( subsize[v] > mx ) {
            mx = subsize[v] ;
            sc = v ;
            new_cost = costs[u][i] ;
        }
    }
    if( sc != -1 ) {
        hld(sc , u , new_cost) ;
    }
    for( int i = 0 ; i < len ; i++ ) {
        int v = G[u][i] ;
        if( v == p ) continue ;
        if( v != sc ) {
            chainNo += 1 ;
            hld(v , u , costs[u][i]) ;
        }
    }
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */
int query_up( int u , int v ) {
    if( u == v ) return 0 ;
    int uchain , vchain = chainInd[v] , answer = -1 ;
    while( true ) {
        uchain = chainInd[u] ;

        /*u and v are in same chain*/
        if( uchain == vchain ) {
            if( u == v ) break ;
            int now = query(1 , 1 , ptr , posInBase[v] + 1 , posInBase[u]) ;
            answer = max(answer , now) ;
            break ;
        }
        int now = query(1 , 1 , ptr , posInBase[chainHead[uchain]] , posInBase[u]) ;
        answer = max(answer , now) ;
        u = chainHead[uchain] ;
        u = par[u][0] ;
    }
    return answer ;
}

/*
 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
 */
int query( int u , int v ) {
    int LCA = lca(u , v) ;
    int x = query_up(u , LCA) ;
    int y = query_up(v , LCA) ;
    return max(x , y) ;
}


/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change( int id , int val ) {
    int u = otherEnd[id] ;
    upd(1 , 1 , ptr , posInBase[u] , posInBase[u] , val) ;
}

/*
 * prepare_hld:
 * After processing input this function calls other
 * functions in correct order to perform HLD
 */
void prepare_hld() {
    dfs(1 , -1 , 0) ;
    hld(1 , -1 , -1) ;
    build(1 , 1 , ptr) ;
    prepare_lca() ;
}

/*
 * init:
 * Before taking input this function clears out everything
 */
void init( int _n = 100000 ) {
    ptr = 0 , chainNo = 1 ;
    for( int i = 0 ; i <= n ; i++ ) {
        G[i].clear() ;
        costs[i].clear() ;
        indexx[i].clear() ;
        chainHead[i] = -1 ;
        for( int j = 0 ; j <= LOG ; j++ ) {
            par[i][j] = -1 ;
        }
    }
}
/*Uses 1 based indexing and nodes are numbered from 1 to n*/
int main() {
//    freopen("in.txt" , "r" , stdin) ;
    int T ; scanf("%d" , &T ) ;
    while( T-- ) {
        scanf("%d" , &n ) ;
        init() ;
        for( int i = 1 ; i < n ; i++ ) {
            int u , v , c ; scanf("%d %d %d" , &u , &v , &c ) ;
            G[u].push_back(v) ;
            costs[u].push_back(c) ;
            indexx[u].push_back(i) ;

            G[v].push_back(u) ;
            costs[v].push_back(c) ;
            indexx[v].push_back(i) ;
        }
        prepare_hld() ;
        char s[100] ;
        while(true) {
            scanf("%s" , &s ) ;
            if( s[0] == 'D' ) break ;
            if( s[0] == 'Q' ) {
                int u , v ; scanf("%d %d" , &u , &v ) ;
                printf("%d\n" , query(u , v)) ;
            } else {
                int edge , val ; scanf("%d %d" , &edge , &val) ;
                change(edge , val) ;
            }
        }
    }
    return 0 ;
}
/*
 problem: spoj QTREE
 Given a tree, you need to find maximum cost of edges in the path u to v
 update cost of edge u-v
*/
/*
input
1
3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
*/
