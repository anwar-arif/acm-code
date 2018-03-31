#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define LL long long
#define pb push_back
#define mx 20005
#define inf 999999

struct edge
{
        int u,w;

        bool operator < (const edge & p)const
        {
                return w > p.w;
        }
};

vector < int > g[mx],cost[mx];
int level[mx];

void reset()
{
        for(int i = 0 ; i < mx ; i++)
        {
                g[i].clear();
                cost[i].clear();
                level[i] = inf;
        }
}

int dijkstra(int s, int t)
{
        int u, v, len, i;
        priority_queue < edge > q;

        edge get;
        get.u = s;
        get.w = 0;
        q.push(get);
        level[s] = 0;

        while(!q.empty())
        {
                edge top = q.top();
                q.pop();
                u = top.u; //pf("top %d\n",u);

                if(u == t) return level[u];

                len = (int) g[u].size();

                for(i = 0 ; i < len ; i++)
                {
                        v = g[u][i]; //pf("v is %d level of v=%d is %d\n",v,v,level[v]);
                        if(level[v] > level[u] + cost[u][i])
                        {
                                level[v] = level[u] + cost[u][i];
                                edge get;
                                get.u = v;
                                get.w = level[v]; //pf("level of v=%d is %d\n",v,level[v]);
                                q.push(get);
                        }
                }
        }
        return -1;
}

int main()
{
        int tst, cas, n, m, s, t, u, v, w, ans, i;
        sc("%d",&tst);
        for(cas = 1; cas <= tst ; cas++)
        {
                reset();
                sc("%d %d %d %d",&n, &m, &s, &t);
                for(i = 0 ; i < m ; i++)
                {
                        sc("%d %d %d",&u, &v, &w);
                        g[u].pb(v);
                        g[v].pb(u);

                        cost[u].pb(w);
                        cost[v].pb(w);
                }

                ans = dijkstra(s,t);

                if(ans == -1)
                {
                        pf("Case #%d: unreachable\n",cas);
                }
                else
                {
                        pf("Case #%d: %d\n",cas,ans);
                }

        }
        return 0;
}
