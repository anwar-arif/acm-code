#include <bits/stdc++.h>
using namespace std;

const int N = 100+5;

int parent[N],cost[N][N],n;
vector<int>g[N];

bool bfs(int s,int t){

    parent[s] = s;
    bool visited[n+3];
    mem(visited,false);
    queue<int>q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){

        int u = q.front(); q.pop();
        int len = SZ(g[u]);

        for(int i = 0 ;i < len; i++){

            int v = g[u][i];

            if(visited[v] == false and cost[u][v] > 0){

                visited[v] = true;
                parent[v] = u;
                if(v == t)return true;
                q.push(v);
            }
        }
    }
    return visited[t]==true;
}

int fordFulkerson(int s,int t){
    int mx_flow = 0;

    while(bfs(s,t) == true){

        int path_flow = INT_MAX;

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            path_flow = min(path_flow,cost[u][v]);
        }

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            cost[u][v] -= path_flow;
            cost[v][u] += path_flow;
        }

        mx_flow += path_flow;
    }
    return mx_flow;
}

int main()
{

      int tst,cas = 0;
      sc1i(tst);
      while(tst--)
      {
          int s,t,e,u,v,w;
          sc1i(n);
          sc3i(s,t,e);

          for(int i = 0; i <= n;i++){
              g[i].clear();
              for(int j =0 ;j <= n;j++){
                  cost[i][j] = 0;
              }
          }

          for(int i = 0 ; i < e;i++){
              sc3i(u,v,w);
              g[u].pb(v);
              g[v].pb(u);
              cost[u][v] += w;
              cost[v][u] += w;
          }
          pf("Case %d: %d\n",++cas,fordFulkerson(s,t));
      }
      return 0;
}
/*
    complexity : maxflow*Edges
*/
