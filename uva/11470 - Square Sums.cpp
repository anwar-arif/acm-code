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

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define pi acos(-1)
#define mx 10000

int main()
{
    int cas = 0,n,a[11][11],T,s,r,c,i,j;
    while(sc1i(n) == 1)
    {
        if(n == 0){return 0;}
        for(i = 1;i<=n;i++)
        {
            for(j = 1; j <= n;j++)
            {
                sc1i(a[i][j]);
            }
        }
        T = (int)ceil((double) n/2);
        pf("T = %d\n",T);
        pf("Case %d:",++cas);
        for(i = 1; i<= T;i++)
        {
            s = 0;
            r = i;
            for(c = i; c <= n - i +1; c++)
            {
                s += a[r][c];
            }
            c = i;
            for(r = i; r <= n - i +1 ;r++)
            {
                s += a[r][c];
            }
            r = n - i + 1;
            for(c = i ; c <= n - i + 1; c++)
            {
                s += a[r][c];
            }
            c = n - i +1;
            for(r = i ; r<= n- i + 1; r++)
            {
                s += a[r][c];
            }
            pf(" %d",s);
        }
        pf("\n");
    }
    return 0;
}
