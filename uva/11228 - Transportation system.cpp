#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

struct cor
{
        int x,y;
};

struct edge
{
        int u,v;
        double w;
        bool operator < (const edge& p)const
        {
                return w<p.w;
        }
};

vector<cor>g;
vector<edge>graph;
int par[1005];

int findpar(int r)
{
        return (par[r]==r)? r : findpar(par[r]);
}

int main()
{
        int tst,cas,n,r,x,y,j,siz,u,v,stat,i;
        double dist,rail,road;
        sc("%d",&tst);
        for(cas=1;cas<=tst;cas++)
        {
                sc("%d%d",&n,&r);
                for(i=0;i<n;i++)
                {
                        sc("%d%d",&x,&y);
                        cor get;
                        get.x=x;
                        get.y=y;
                        g.pb(get);
                        par[i]=i;
                }
                par[n]=n;

                for(i=0;i<n;i++)
                {
                        for(j=i+1;j<n;j++)
                        {
                                dist= sqrt( ( (g[i].x - g[j].x) * (g[i].x - g[j].x) ) +
                                        ( (g[i].y - g[j].y) * (g[i].y - g[j].y) ) );
                               edge get;

                               get.u=i;
                               get.v=j;
                               get.w=dist;

                               graph.pb(get);
                        }
                }

                sort(graph.begin(),graph.end());

                siz=(int)graph.size();
                road=0.0,rail=0.0;
                stat=1;
                int cnt=0;

                for(i=0;i<siz ;i++)
                {
                        u=findpar(graph[i].u);
                        v=findpar(graph[i].v);
                        if(u!=v)
                        {
                                par[u]=v;
                                ++cnt;
                                if(graph[i].w>r)
                                {
                                        ++stat;
                                        rail+=graph[i].w;

                                }
                                else
                                {
                                        road+=graph[i].w;
                                }
                        }
                }
                int rd= int (road+0.5);
                int rl= int (rail+0.5);

                pf("Case #%d: %d %d %d\n",cas,stat,rd,rl);
                g.clear();
                graph.clear();
        }
        return 0;
}
