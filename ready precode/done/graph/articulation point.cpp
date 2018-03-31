
const int N = 1e6 + 5;

vector<int>g[N] ;

bool vis[N] , art[N];

int par[N] , dis[N] , fin[N] , depth;

void reset(){

    depth = 0;

    rep(i,0,N-2){
        g[i].clear();
        vis[i] = false;
        par[i] = -1;
        art[i] = false;
    }
}

void dfs(int u){

    vis[u] = true;
    dis[u] = fin[u] = depth++;

    int child = 0;

    int len = SZ(g[u]);

    for(int i = 0 ;i < len ;i++){

        int v = g[u][i] ;

        if(!vis[v]){

            ++child;
            par[v] = u;

            dfs(v) ;

            dis[u] = min(dis[u] , dis[v]);

            if(par[u] != -1){
                if(dis[v] >= fin[u]){
                    art[u] = true;
                }
            }
        }
        else if(v != par[u]){

            dis[u] = min(dis[u] , fin[v]);
        }
    }
    if(par[u] == -1){

        if(child > 1){
            art[u] = true;
        }
    }
}

int main(){
    int tst,cas = 0;
    sc1i(tst) ;

    int n , m;

    while(tst--){
        sc2i(n,m);

        reset();

        int u , v;
        rep(i,1,m){

            sc2i(u,v) ;

            g[u].pb(v) ;
            g[v].pb(u) ;
        }

        rep(i,1,n){

            if(!vis[i])dfs(i);
        }

        int tot = 0;

        rep(i,1,n){

            tot += (art[i] == true);
        }
        pf("Case %d: %d\n",++cas,tot);
    }
}

