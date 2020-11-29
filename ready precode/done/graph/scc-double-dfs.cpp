
#define SIZ 10000+5

stack<int>st;
bool visited[SIZ],color[SIZ];
vector<int>components[SIZ],g[SIZ],rg[SIZ];

void dfs(int u){
    color[u] = true;
    int len = SZ(g[u]);
    for(int i = 0 ;i < len;i++){
        int v = g[u][i];
        if(color[v] == false){
            dfs(v);
        }
    }
    st.push(u);
    return;
}

void dfs2(int u,int mark){
    components[mark].pb(u);///mark = scc number
    visited[u] = true;
    int len = SZ(rg[u]);
    for(int i = 0 ; i < len;i++){
        int v = rg[u][i];///reverse
        if(visited[v] == false){
            dfs2(v,mark);
        }
    }
    return;
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas = 0 , n,m,a,b;
      sc1i(tst);
      while(tst--){
        sc2i(n,m);
        for(int i = 0 ;i <=n+2;i++){
            components[i].clear();
            g[i].clear();
            rg[i].clear();
        }
        for(int i = 1; i<= m;i++){
            sc2i(a,b);
            g[a].pb(b);
            rg[b].pb(a);
        }
        while(!st.empty()){st.pop();}

        mem(visited,false);
        mem(color,false);

        for(int i = 1;i<=n;i++){
            if(color[i] == false){
                dfs(i);
            }
        }
        int cnt = 0;
        while(!st.empty()){
            int u = st.top(); st.pop();
            if(visited[u] == false){
                dfs2(u,++cnt);
            }
        }
        pf("total scc %d\n",cnt);
      }
      return 0;
}
//if the cycle remains same in reverse graph then these cycle is a scc
