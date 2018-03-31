
const int N = 10000+5;
const int LOG = 20 ;

vector<int>g[N];
int level[N],par[N][LOG+5],t[N],n;

void dfs( int u , int p , int d ) {
    int len = SZ(g[u]) ;
    level[u] = d ;
    for( int i = 0 ;i < len ;i++ ){
        int v = g[u][i];
        if( v != p ) {
            t[v] = u ;
            dfs( v , u , d+1 ) ;
        }
    }
}

void ith_parent(){

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= LOG;j++){
            par[i][j] = -1;
        }
    }

    for(int i = 1; i<= n;i++){
        par[i][0] = t[i];
    }

    for(int j = 1;j <= LOG ; j++){
        for(int i = 1; i <= n;i++){
            if(par[i][j-1] != -1){
                par[i][j] = par[ par[i][j-1] ][j-1];
                ///as 2^(x-1) + 2^(x-1) = 2^x
            }
        }
    }
}

int lca(int p,int q){

    if(level[p] < level[q]){
        int tmp = p; p = q; q = tmp;
    }

    for(int i = LOG; i >= 0;i--){
        if(level[p] - power(2,i) >= level[q]){
            p = par[p][i];
        }
    }

    if(p == q)return p;

    for(int i = LOG ; i >= 0;i--){
        if(par[p][i] !=-1 and par[p][i] != par[q][i]){
            p = par[p][i];
            q = par[q][i];
        }
    }
    return t[p];
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int edge,u,v,root,a,b;
      sc2i(n,edge);
      for(int i = 0 ; i < edge;i++){
          sc2i(u,v);
          g[u].pb(v);
          t[v] = u;///t[] = imidiate parent of i
      }
      sc1i(root);
      sc2i(a,b);

      t[root] = root ;
      dfs(root , root , 0) ;
      ///bfs to make level array
      ///root can be find by top sort

      ith_parent();///calculate 2^i th parent of every node

      int ans = lca(a,b);

      pf("lca is %d\n",ans);

      return 0;
}

