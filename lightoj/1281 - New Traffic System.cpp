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
#define mx 10001

int cnt,dist[mx+1];

struct edge
{
        int u,w;
        bool operator < (const edge & p)const
        {
                return w > p.w;
        }
};

vector<int>g[mx+1],cost[mx+1];

int fun(int s,int t)
{
        priority_queue<edge>q;
        int len,i,u,v;
        edge get;
        get.u = s;
        get.w = 0;
        dist[s] = 0;
        q.push(get);
        cnt = 0;
        while(!q.empty()){
                edge top = q.top();q.pop();
                u = top.u;pf("u is %d\n",u);
                if(u == t)return dist[u];
                len = (int)g[u].size();
                for(i = 0; i<len;i++){
                        v = g[u][i];
                        if(dist[u] + cost[u][v] < dist[v]){
                                dist[v] = dist[u] + cost[u][v];
                                edge get;
                                get.u = v;
                                get.w = dist[v];
                                q.push(get);
                                ++cnt;pf("v = %d   dist = %d\n",v,dist[v]);
                        }
                }
        }
        return -1;
}

void reset()
{
        for(int i = 0; i < mx;i++){
                g[i].clear();
                cost[i].clear();
                dist[i] = inf;
        }
}

int main()
{
        int tst,cas,n,m,k,d,ans,i,u,v,w;
        sc1i(tst);
        for(cas = 1; cas <= tst;cas++){
                reset();
                sc4i(n,m,k,d);
                for(i = 0;i < (m+k) ;i++){
                        sc3i(u,v,w);
                        g[u].pb(v);
                        g[v].pb(u);
                        cost[u].pb(w);
                        cost[v].pb(w);
                }
                ans = fun(0,n-1);
                if((ans == -1 ) || (cnt > d)){
                        pf("Case %d: Impossible\n",cas);
                }else{
                      pf("Case %d: %d\n",cas,ans);
                }
        }
        return 0;
}
