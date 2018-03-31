#include<bits/stdc++.h>
using namespace std;

vector<int>vc[1005];
bool vis[1111];
int level[1111];


void bfs(int u)
{
    memset(level,-1,sizeof level);
    level[u]=0;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0; i<vc[v].size(); i++)
        {
            u=vc[v][i];
            if(level[u]==-1)
            {
                level[u]=level[v]+1;
                q.push(u);
            }
        }
    }
}


int dfs(int u,int mv,int pr)
{
    if(level[u]<mv) return 1;
    int r=0;
    for(int i=0; i<vc[u].size(); i++)
    {
        int v=vc[u][i];
        if(v==pr) continue;
        int rt=dfs(v,mv+1,u);
        if(rt==0) r=1;
    }
    return r;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,i,u,v;
    scanf("%d %d",&n,&m);
    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&u,&v);
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    memset(vis,0,sizeof vis);
    bfs(1);
    memset(vis,0,sizeof vis);
    int r=dfs(1,0,1);
    if(r) printf("Vladimir\n");
    else printf("Nikolay\n");




}
