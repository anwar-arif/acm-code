#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back

int cost[500];

int bfs(int n)
{
        int ;
        for(i=1;i<=n;i++)
        {
                cost[i]=9999999999;
        }
        queue<int>q;
        q.push(1);
        cost[1]=0;
        while(!q.empty())
        {
                int u=q.front();
                siz=(int)g[u].size();
                for(i=0;i<siz;i++)
                {

                }
        }
}

int main()
{
        int ;
        sc("%d",&tst);
        for(cas=1;cas<=tst;cas++)
        {
                sc("%d",&n);
                for(i=1;i<=n;i++)
                {
                        sc("%d",&a[i]);
                }
                sc("%d",&m);
                for(i=0;i<m;i++)
                {
                        sc("%d%d",&a,&b);
                        v[a].pb(b);

                }
                bfs();

        }
}
