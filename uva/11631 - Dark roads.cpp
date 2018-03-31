#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define LL long long
#define pb push_back

struct edge
{
        int u,v,w;
        bool operator < (const edge& p)const
        {
                return w<p.w;
        }
};

vector<edge>g;
int m,n;
int par[200000+10];

int findpar(int r)
{
        return (par[r]==r)? r : par[r]=findpar(par[r]);
}

int mst()
{
        int i,result=0,x,y,cnt=0;
        sort(g.begin(),g.end());
        int siz=(int)g.size();

        for(i=0;i<siz;i++)
        {
                x=findpar(g[i].u);
                y=findpar(g[i].v);
                if(x!=y)
                {
                        par[x]=y;
                        ++cnt;
                        result+=g[i].w;
                        if(cnt==m-1)break;
                }
        }
        return result;
}

int main()
{
        int cost,i,u,v,w,ans;

        while(sc("%d%d",&m,&n)==2)
        {
                if(m==0 && n==0)break;
                g.clear();

                cost=0;
                for(i=0;i<n;i++)
                {
                        sc("%d%d%d",&u,&v,&w);

                        cost+=w;
                        edge get;
                        par[i]=i;

                        get.u=u; get.v=v; get.w=w;
                        g.pb(get);
                }
                par[n]=n;
                ans=mst();

                pf("%d\n",cost-ans);
        }
        return 0;
}
