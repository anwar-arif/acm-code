#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 11111;
int dis[MAXN],fin[MAXN],belong[MAXN],deg[MAXN],ans,scc,t,n,m,depth;
vector<int> g[MAXN],gs[MAXN];
stack<int> s;

void init()
{
   for(int i=0; i<MAXN; i++)g[i].clear(),gs[i].clear();
   memset(fin,-1,sizeof(fin));
   memset(belong,-1,sizeof(belong));
   memset(deg,0,sizeof(deg));
   ans = scc = depth = 0 ;
   while(!s.empty())s.pop();
}

void tarjan(int u)
{
   dis[u] = fin[u] = depth++;
   s.push(u);

   for(int i=0; i<(int)g[u].size(); i++)
   {
       int v = g[u][i];
       if(fin[v] == -1)
       {
           tarjan(v);
           dis[u] = min(dis[u],dis[v]);///dis = temporary circle number
       }
       else if(belong[v] == -1)
       {
           dis[u] = min(dis[u],fin[v]);
       }
   }
   if(dis[u]==fin[u])
   {
       int v;
       do
       {
           v = s.top();
           belong[v] = scc;///final circle number
           s.pop();
       }
       while(v!=u);
       scc++;
   }
}

void DFS(int u)
{
   fin[u] = 1;
   for(int i=0; i<(int)g[u].size(); i++)
   {
       int v = g[u][i];
       if(belong[u]!=belong[v])deg[belong[v]]++;
       if(!fin[v])DFS(v);
   }
}

void solve()
{
   for(int i=0; i<scc; i++)if(!deg[i])ans++;
}

int main()
{
   scanf("%d",&t);
   for(int cas=1; cas<=t; cas++)
   {
       init();
       scanf("%d%d",&n,&m);
       while(m--)
       {
           int a,b;
           scanf("%d%d",&a,&b);
           a--,b--;
           g[a].push_back(b);
       }
       for(int i=0; i<n; i++){
            if(fin[i]==-1)tarjan(i);
       }
       memset(fin,0,sizeof(fin));
       for(int i=0; i<n; i++){
            if(!fin[i])DFS(i);///fin = visit and fast see
       }
       solve();
       for(int i = 0 ; i < n;i++){
           pf("i %d belong %d\n",i,belong[i]);
       }
       printf("Case %d: %d\n",cas,ans);
   }
   return 0;
}
