
const int N = 4e5 + 10;

ll tym , arr[N] , start[N] , fin[N] ,col[N] , n , q;
ll lazy[4*N] , tree[4*N] ;
vector<ll>g[N] ;

void dfs(ll u , ll p){
    start[u] = ++tym;
    int len = SZ(g[u]);
    for(int i = 0 ;i < len ;i++){
        ll v = g[u][i];
        if(v == p)continue;
        dfs(v , u);
    }
    arr[tym] = col[u] ;
    fin[u] = tym;
}

void build(ll node , ll b , ll e){
    if(b == e){
        tree[node] = arr[b] ;
        lazy[node] = -1;
        return;
    }
    ll lft , rt , mid ;
    lft = node * 2 , rt = lft + 1 , mid = (b + e) / 2;
    build(lft , b , mid);
    build(rt , mid + 1 , e);
    tree[node] = (tree[lft] | tree[rt]);
    lazy[node] = -1;
}

void update(ll node , ll b , ll e , ll i , ll j , ll v){
    if(e < i || b > j)return;
    if(b >= i && e <= j){
        tree[node] = (1LL << v);
        lazy[node] = v;
        return;
    }
    ll lft , rt , mid ;
    lft = node * 2 , rt = lft + 1 , mid = (b + e) / 2;

    ///push_down
    if(lazy[node] != -1){
        update(lft , b , mid , b , e , lazy[node]);
        update(rt , mid+1 , e , b , e , lazy[node]);

        lazy[node] = - 1;
        tree[node] = (tree[lft] | tree[rt]);
    }

    update(lft , b , mid , i , j , v);
    update(rt , mid + 1 , e , i , j , v) ;

    tree[node] = (tree[lft] | tree[rt]);
    lazy[node] = -1;
}

ll query(ll node , ll b , ll e , ll i , ll j){
    if(e < i || b > j)return 0;
    if(b >= i && e <= j)return tree[node];

    ll lft , rt , mid ;
    lft = node * 2 , rt = lft + 1 , mid = (b + e) / 2;

    ///push_down
    if(lazy[node] != -1){
        update(lft , b , mid , b , e , lazy[node]);
        update(rt , mid+1 , e , b , e , lazy[node]);

        lazy[node] = - 1;
        tree[node] = (tree[lft] | tree[rt]);
    }
    return (query(lft , b , mid , i , j) | query(rt , mid + 1 , e , i , j));
}

void reset(){
    for(int i = 0 ;i < N-2 ;i++){
        g[i].clear();
    }
}

int main(){

    ll u , v , x , typ , c;
    while(sc2ll(n , q) != EOF){
        reset();
        rep(i , 1 , n){
            sc1ll(x);
            --x;
            col[i] = (1LL << x) ;///color of vertex i
        }

        rep(i , 1 , n-1){
            sc2ll(u , v) ;
            g[u].pb(v) ;
            g[v].pb(u) ;
        }

        tym = 0;
        dfs(1 , -1);
        build(1 , 1, n) ;

        rep(i , 1 , q){
            sc2ll(typ , u);
            if(typ == 1){
                ///change the color of all vertex
                /// in the subtree of u to color c

                sc1ll(c);
                --c;
                update(1 , 1 , n , start[u] , fin[u] , c) ;
            }
            else{
                ///find the number of diff color
                /// in the subtree of vertex u

                ll res = query(1 , 1 , n , start[u] , fin[u] );
                res = __builtin_popcountll(res);
                pf("%lld\n",res);
            }
        }
    }
    return 0;
}
