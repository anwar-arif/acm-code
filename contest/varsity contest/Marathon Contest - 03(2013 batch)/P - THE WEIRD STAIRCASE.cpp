#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define ll long long
#define mx 1<<28

int n;
int dist[25],visit[25],a[25];
vector<int > g[25];

void reset()
{
        for(int i = 0; i <= n ;i ++)
        {
                g[i].clear();
                dist[i] = mx;
                visit[i] = 0;
        }
}

int bfs()
{
        int u,v,i,siz;
        queue<int>q;
        q.push(0);
        dist[0] = 0;
        visit[0] = 1;

        while(!q.empty())
        {
                u = q.front(); q.pop();

                if(u == n)return dist[u];

                siz = (int) g[u].size();
                for(i = 0 ; i < siz; i++)
                {
                        v = g[u][i];
                        if(visit[v] != 1)
                        {
                                visit[v] = 1;
                                dist[v] = dist[u] + 1;
                                q.push(v);
                        }
                }
        }
        return -1;
}

int main()
{
        int tst,i;
        sc("%d",&tst);
        while(tst--)
        {
                sc("%d",&n);
                reset();
                for(i = 0; i< n ; i++)
                {
                        sc("%d",&a[i]);
                }

                for(i = 0 ; i< n; i++)
                {
                        g[i].pb(i+1);
                        if(i + a[i] >0 && a[i] + i <= n)
                        {
                                g[i].pb(i+a[i]);
                        }
                }

                pf("%d\n",bfs());
        }
        return 0;
}
