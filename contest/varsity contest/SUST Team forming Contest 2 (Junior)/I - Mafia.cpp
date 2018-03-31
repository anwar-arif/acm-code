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

int main()
{
    ll n,s,ans,a[100005],i,mx;
    while(sc1ll(n) != EOF)
    {
        s = 0;mx = 0;
        for(i = 1; i<= n;i++)
        {
            sc1ll(a[i]);
            s += a[i];
            mx = max(mx,a[i]);
        }
        ans = (int)ceil((double)s/(double)(n-1));
        ans = max(ans,mx);
        pf("%lld\n",ans);
    }
    return 0;
}
