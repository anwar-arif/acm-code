#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define LL long long
#define pb push_back

struct cor
{
    int x,y;
};

struct edge
{
    int u,v;
    double w;
    bool operator < (const edge & p)const
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

double mst()
{
    int i,u,v;
    double res;
    sort(graph.begin(),graph.end());
    int siz=(int)graph.size();
    for(i=0; i<siz; i++)
    {
        u=findpar(graph[i].u);
        v=findpar(graph[i].v);
        if(u!=v)
        {
            par[u]=v;
            if(findpar(0)==findpar(1))
            {
                res=graph[i].w;
                break;
            }
        }
    }
    return res;
}

int main()
{
    int n,i,x,y,j,cas=0;
    double ans,dist;
    while(sc("%d",&n)==1)
    {
        if(n==0)break;
        for(i=0; i<2; i++)
        {
            sc("%d%d",&x,&y);
            cor get;
            get.x=x;
            get.y=y;
            g.pb(get);
            par[i]=i;
        }

        for(i=2; i<n; i++)
        {
            sc("%d%d",&x,&y);
            cor get;
            get.x=x;
            get.y=y;
            g.pb(get);
            par[i]=i;
        }
        par[n]=n;

        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                dist=sqrt( ( (g[i].x -g[j].x) * (g[i].x -g[j].x) ) +
                           (g[i].y - g[j].y ) * ( g[i].y - g[j].y ) );
                edge get;
                get.u=i;
                get.v=j;
                get.w=dist;
                graph.pb(get);
            }
        }

        ans=mst();
        pf("Scenario #%d\nFrog Distance = %0.3lf\n\n",++cas,ans);
        graph.clear();
        g.clear();
    }
    return 0;
}
