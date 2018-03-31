#include <bits/stdc++.h>
using namespace std;
#define pf              printf
#define sc              scanf
#define pb              push_back
#define ll              long long int
#define sc1i(a)         sc("%d",&a)
#define sc2i(a,b)       sc("%d%d",&a,&b)
#define sc3i(a,b,c)     sc("%d%d%d",&a,&b,&c)
#define sc1ll(a)        sc("%lld",&a)
#define sc2ll(a,b)      sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c)    sc("%lld%lld%lld",&a,&b,&c)
#define sz(a)           (int)a.size()
#define pi              acos(-1.0)
#define MX              100001

int st,mark[20005],one,two,take[20005],a[20005],visit[200005];
vector<int>g[20005];

void bfs()
{
    queue<int>q;
    q.push(st);
    int u,v,i,len;
    mark[st] = 1;
    ++one;
    visit[st] = 1;
    while(!q.empty())
    {
        u = q.front();q.pop();
        len = (int) g[u].size();
        for(i  = 0 ;i < len;i++)
        {
            v = g[u][i];
            visit[v] = 1;
            if(mark[v] == 0)
            {
                q.push(v);
            }
            if(mark[u] == 1)
            {
               if(mark[v] == 0){mark[v] = 2;++two;}
            }
            else if(mark[u] == 2)
            {
                if(mark[v] == 0){mark[v] = 1;++one;}
            }
        }
    }
}

void init()
{
    for(int i = 0 ; i < 20005;i++)
    {
        g[i].clear();
        mark[i] = 0;
        take[i] = 0;
        a[i] = 0;
        visit[i] = 0;
    }
}

int main()
{
        int tst,cas,i,n,p,siz,mx,u,v,k,ans;
        sc1i(tst);
        for(cas = 1; cas <= tst;cas++)
        {
                init();
                sc1i(n);
                k = 0;
                for(i = 1; i<= n;i++)
                {
                    sc2i(u,v);
                    g[u].pb(v);
                    g[v].pb(u);
                    if(take[u] == 0)
                    {
                        take[u] = 1;
                        a[++k] = u;
                    }
                    if(take[v] == 0)
                    {
                        take[v] = 1;
                        a[++k] = v;
                    }
                }
                ans = 0;
                for(i = 1; i <= k;i++)
                {
                    if(mark[a[i]] == 0)
                    {
                        one = two = 0;
                        st = a[i];
                        bfs();
                        ans += max(one,two);
                    }
                }
                pf("Case %d: %d\n",cas,ans);
        }
        return 0;
}
