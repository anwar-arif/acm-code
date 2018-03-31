#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long
#define pb push_back

int main()
{
    int deg[110] , res[110] , i , j , n , m , k , siz , u , v , y;

    int connected[110][110];

    while(sc("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)break;

        queue<int>q;

        memset(deg,0,sizeof(deg));
        memset(res,0,sizeof(res));

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n ; j++)
            {
                connected[i][j] = 0;
            }
        }

        for(i = 1; i <= m; i++)
        {
            sc("%d%d",&u,&v);

            connected[u][v] = 1;

            ++deg[v];///indegree
        }

        for(i = 1; i <= n; i++)
        {
            if(deg[i] == 0)q.push(i);
        }

        k = 0;///result index

        while(!q.empty())
        {
            u = q.front();
            q.pop();

            res[++k] = u;///b = result array

            for(i = 1; i <= n; i++)
            {
                if(connected[u][i] == 1)
                {
                    --deg[i];
                    if(deg[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }

        for(i = 1; i < k ; i++)
        {
            pf("%d ",res[i]);
        }
        pf("%d\n",res[k]);

    }
    return 0;
}

//input :
//5 4
//1 2
//2 3
//1 3
//1 5
//
//output : 1 4 2 5 3
