#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back

struct edge
{
        int u,v;
        double w;
        bool operator < (const edge & p)const
        {
                return w<p.w;
        }
};

vector<edge>g;
int par[500];
vector<int>v[1000];


int findpar(int r)
{
        return (par[r]==r)?r : findpar(par[r]);
}

int mst(int tar)
{
        int siz,i,cost,u,v;
        sort(g.begin(),g.end());
        siz=(int)g.size();
        cost=0;
        for(i=0;i<siz;i++)
        {
                u=findpar(g[i].u);
                v=findpar(g[i].v);
                if(u!=v)
                {
                        par[u]=v;
                        cost+=g[i].w;
                        if(v==tar)return cost;
                }
        }
        return -1;
}

int bfs(int tar)
{
        int ;
        queue<int>q;

}

int main()
{
        int tst,cas,n,i,a[500],dist,m,n1,n2,q,tar,ans;
        sc("%d",&tst);
        for(cas=1;cas<=tst;cas++)
        {
                sc("%d",&n);
                for(i=1;i<=n;i++)
                {
                        sc("%d",&a[i]);
                        par[i]=i;
                }
                sc("%d",&m);
                for(i=0;i<m;i++)
                {
                        sc("%d%d",&n1,&n2);
                        dist= int (pow(double(abs((a[n1] - a[n2])) ) ,3) );
                        edge get;
                        get.u=n1;get.v=n2;get.w=dist;
                        g.pb(get);
                        v[n1].pb(n2);
                }

                sc("%d",&q);

                for(i=1;i<=q;i++)
                {
                        sc("%d",&tar);
                        ans=mst(tar);
                        pf("%d\n",ans);
                }
        }
        return 0;
}
