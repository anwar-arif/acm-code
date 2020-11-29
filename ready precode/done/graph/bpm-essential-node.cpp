
const int N = 200+10;

bool removed[N],visited[N];
vector<int>g[N];
int match[N] , n , m , grp[N];

bool dfs(int u){
    if(removed[u])return false;
    int len = SZ(g[u]);
    for(int i = 0  ;i < len;i++){
        int v = g[u][i];
        if(!removed[v] and !visited[v]){
            visited[v] = true;
            if(match[v] < 0 or dfs(match[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm(){
    int cnt = 0;
    mem(match,-1);
    for(int i = 0 ;i < n;i++){
        mem(visited,false);
        if(dfs(i))++cnt;
    }
    return cnt;
}

void reset(){
    for(int i = 0 ;i <= n;i++){
        g[i].clear();
    }
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas = 0,u,v;
      sc1i(tst);
      while(tst--){
          sc2i(n,m);
          reset();
          for(int i = 0;i < n;i++){
              sc1i(grp[i]);
          }
          for(int i = 0  ;i < m;i++){
              sc2i(u,v);
              if(grp[u] != grp[v]){
                  if(grp[u] == 0){
                      g[u].pb(v);
                  }else g[v].pb(u);
              }
          }
          mem(removed,false);
          int tot = bpm();
          pf("%d",tot);
          int ans[N] , k = 0;
          for(int i = 0 ;i < n;i++){
              removed[i] = true;
              int cur = bpm();
              if(cur < tot){
                  tot = cur;
                  ans[++k] = i;
                  if(tot == 0)break;
              }else removed[i] = false;
          }
          sort(ans+1,ans+1+k);
          for(int i = 1; i<= k;i++){
              pf(" %d",ans[i]);
          }pf("\n");
      }
      return 0;
}
