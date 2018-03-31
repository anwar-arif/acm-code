#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long
#define pb push_back

int main()
{
        int a[110],b[110],i,j,n,m,k,siz,u,x,y;
        int v[110][110];
        while(sc("%d%d",&n,&m) == 2)
        {
                if(n == 0 && m == 0)break;


                queue<int>q;
                memset(a,0,sizeof(a));
                memset(b,0,sizeof(b));

                for(i = 1; i <= n; i++)
                {
                        for(j = 1; j <= n ; j++)
                        {
                                v[i][j] = 0;
                        }
                }

                for(i = 1; i <= m; i++)
                {
                        sc("%d%d",&x,&y);
                        v[x][y] = 1;
                        ++a[y];
                }

                for(i = 1; i <= n; i++)
                {
                        if(a[i] == 0)q.push(i);
                }

                k = 0;

                while(!q.empty())
                {
                        u = q.front(); q.pop();

                        b[++k] = u;

                        for(i = 1; i <= n; i++)
                        {
                                if(v[u][i] == 1)
                                {
                                        --a[i];
                                        if(a[i] == 0)
                                        {
                                                q.push(i);
                                        }
                                }
                        }
                }

                for(i = 1; i < k ;i++)
                {
                        pf("%d ",b[i]);
                }
                pf("%d\n",b[k]);

        }
        return 0;
}
