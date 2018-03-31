#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define pi acos(-1.0)

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

int main()
{
    ll tst,cas = 0,x1,y1,x2,y2;
    sc1ll(tst);
    while(tst--)
    {
        sc4ll(x1,y1,x2,y2);
        x1 = abs(x1-x2);
        y1 = abs(y1-y2);
        if(x1 == y1)
        {
            pf("Case %lld: 1\n",++cas);
        }
        else
        {
            if(x1%2==y1%2)
            {
                pf("Case %lld: 2\n",++cas);
            }
            else pf("Case %lld: impossible\n",++cas);
        }
    }
}
