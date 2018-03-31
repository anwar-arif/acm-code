#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define sc1ll(a) sc("%I64d",&a)
#define sc2ll(a,b) sc("%I64d%I64d",&a,&b)
#define sc3ll(a,b,c) sc("%I64d%I64d%I64d",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define pi acos(-1)
#define mod 100000007
#define inf 1<<28
#define mx 160000

struct edge
{
        ll int u,w;
        bool operator < (const edge & p)const
        {
                return w > p.w;
        }
};

ll int n,m;
vector<ll int>g[mx],cost[mx];
ll int d[mx],par[mx],ar[mx];

void reset()
{
        for(ll int i = 0; i <= n; i++)
        {
                g[i].clear();
                cost[i].clear();
                par[i] = -1;
                ar[i] = -1;
                d[i] =1000000000000;
        }
}

void take_input()
{
        ll int i,w,u,v;
        for(i = 1; i <= m; i++)
        {
                sc("%lld%lld%lld",&u ,&v ,&w);


                cost[u].pb(w);
                cost[v].pb(w);

                g[u].pb(v);
                g[v].pb(u);
        }
}

int cal()
{
        ll int u,v,len,i;
        priority_queue <edge>q;
        edge get;
        get.u = 1;
        get.w = 0;
        d[1] = 0;
        par[1] = -1;
        q.push(get);

        while(!q.empty())
        {
                edge top;
                top = q.top(); q.pop();

                u = top.u;//pf("u is %lld\nn is %lld\n",u,n);
                //pf("u is %lld\n",u);
                if(u == n){return d[u];}

                len = (int) g[u].size();

                for(i = 0; i <len ;i++)
                {
                        v = g[u][i];//pf("v is %lld\n",v); //pf("d[%lld] is %lld\n",v,d[v]);

                        if(d[v] > d[u] + cost[u][i])
                        {
                                d[v] = d[u] + cost[u][i];
                                get.u = v;
                                get.w = d[v];
                                par[v] = u; //pf("d[v] is %lld\n",d[v]);
                                q.push(get);
                        }
                }
        }
        return -1;
}

int main()
{

        ll int p,k,i;
        while(sc("%lld%lld",&n,&m) == 2)
        {
                reset();
                take_input();
                int ans = cal();//pf("ans is %lld\n",ans);

                if(ans == -1)
                {
                        pf("-1\n");
                        continue;
                }

                p = n;k = 0;
                while(p != -1)
                {
                        ar[++k] = p;
                        if(p == 1)break;
                        p = par[p];

                }

                for(i = k ; i >= 1; i--)
                {
                        pf("%lld ",ar[i]);
                }

                /*
                pf("%d",ar[k]);
                for(i = k-1; i >= 1; i--)
                {
                        pf(" %d",ar[i]);
                }
                */
                pf("\n");
        }
        return 0;
}
