#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define pi acos(-1.0)
#define inf 9999999999

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

char a[22][22];
int visit[22][22],X,Y,cnt;

void dfs(int x,int y)
{
    if(x > X or x < 1 or y > Y or y < 1)return;
    int i,nx,ny;
    for(i = 0 ; i < 4;  i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx >= 1 and nx <= X and ny <= Y and ny >=1)
        {
            if(a[nx][ny] == '.' and visit[nx][ny] == -1)
            {
                ++cnt;//pf("cnt = %d\n",cnt);
                visit[nx][ny] = 1;
                 dfs(nx,ny);
            }
        }
    }
}

int main()
{
    int tst,cas,i,j,sx,sy;
    sc1i(tst);
    cas = 0 ;
    while(tst--)
    {
        sc2i(Y,X);
        getchar();
        for(i = 1; i <= X;i++)
        {
            for(j = 1; j<= Y;j++)
            {
                sc("%c",&a[i][j]);
                if(a[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
            }
            getchar();
        }
        memset(visit,-1,sizeof(visit));
        cnt = 0;
        dfs(sx,sy);
        pf("Case %d: %d\n",++cas,cnt+1);
    }
    return 0;
}
