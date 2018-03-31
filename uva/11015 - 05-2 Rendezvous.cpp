#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define ll long long
#define siz 23
#define mx 1<<28

int n,m,cost,edge[siz][siz];

void reset(int n)
{
        int i,j;
        for(i = 1; i <= n; i ++)
        {
                for(j = 1 ; j <= n ; j ++)
                {
                        edge[i][j] = mx;

                }
                edge[i][i] = 0;
        }
}

void fw()
{
        int i,j,k;

        for(k = 1; k <= n; k++)
        {
                for(i = 1; i <= n ;i++)
                {
                        for(j = 1; j <= n ;j++)
                        {
                                edge[i][j] = min( edge[i][j], ( edge[i][k] + edge[k][j] ) );
                        }
                }
        }

}

int ans()
{
        int i,j,mn,res,x;
        mn = mx;
        for(i = 1; i <= n ; i++)
        {
                cost = 0 ;
                for(j = 1; j <= n ; j++)
                {
                        cost += edge[i][j];
                }

                if(cost < mn){res = i; mn = cost;}

        }
        return res;
}

int main()
{
        int i,u,v,w;
        string s[siz];
        int cas = 0;
        while(sc("%d%d",&n,&m) == 2)
        {
                if(n == 0 && m == 0)break;
                getchar();

                for(i = 1; i <= n;i ++)
                {
                        cin>>s[i];
                }

                reset(n);

                for(i = 1; i <= m ;i ++)
                {
                        sc("%d%d%d",&u,&v,&w);

                        edge[u][v] = edge[v][u] = w;

                }

                fw();

                cout<<"Case #"<<++cas<<" : "<<s[ans()]<<endl;
        }
        return 0;
}
