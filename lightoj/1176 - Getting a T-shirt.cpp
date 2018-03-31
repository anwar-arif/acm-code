#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define pb push_back
#define pi acos(-1.0)
#define mem(a,x) memset(a,x,sizeof(a))
#define all(v) v.begin(),v.end()
#define SZ(a) (int)a.size()

const int N = 10000+5;

map<string,int>m;

vector<int>g[70];
int parent[70] , n , cost[70][70];

void f(int n){
    m.clear();
    m["XXL"] = n+1;m["XL"] = n+2;m["L"] = n+3;m["M"] = n+4;m["S"] = n+5;m["XS"] = n+6;
}

bool bfs(int s,int t){
    parent[s] = s;
    bool visited[n+15];
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
    int tst,cas = 0,col;
    sc1i(tst);
    while(tst--){
        sc2i(col,n);
        f(n);

        for(int i = 0 ; i < 70;i++){
            g[i].clear();
            for(int j = 0;j < 70;j++){
                cost[i][j] = 0;
            }
        }
        string a,b;
        int u,v;
        for(int i = 1; i<= n;i++){
            cin>>a>>b;
            u = i ; v = m[a];

            g[u].pb(v);
            g[v].pb(u);
            cost[u][v] = 1;
            cost[v][u] = 1;

            v = m[b];
            g[u].pb(v);
            g[v].pb(u);
            cost[u][v] = 1;
            cost[v][u] = 1;

            g[0].pb(i);
            g[i].pb(0);
            cost[i][0] = 1;
            cost[0][i] = 1;
        }
        for(int i = n+1; i <= n+1+6;i++){
            int u = i; int v = u+6;
            g[u].pb(v);
            g[v].pb(u);
            cost[u][v] = col;
            cost[v][u] = col;

            g[v].pb(n+13);
            g[n+13].pb(v);
            cost[v][n+13] = 1000000;
            cost[n+13][v] = 1000000;
        }
        int ans = fordFulkerson(0,n+13);
        pf("Case %d: %s\n",++cas,ans>=n?"YES":"NO");
    }
    return 0;
}
