#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define ull  unsigned long long int
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

ull  ncr[31][31],npr[31][31];

ull  com(ull  n,ull  r)
{
    if(r == n)return 1;
    if(r == 1)return n;
    if(ncr[n][r] != -1)return ncr[n][r];
    else {
        ncr[n][r] = com(n-1,r) + com(n-1,r-1);
        return ncr[n][r];
    }
}

ull  per(ull  n,ull  r)
{
    if(r > n)return 0;
    if(r == 1)return n;
    if(npr[n][r] != -1)return npr[n][r];
    ll  ans = 1;
    for(ll  i = n-r+1;i<=n;i++){
        ans *= i;
    }
    npr[n][r] = ans;
    return npr[n][r];
}

int main()
{
    ll  tst,cas,r,n;

    sc1ll(tst);
    memset(npr,-1,sizeof(npr));
    memset(ncr,-1,sizeof(ncr));
    for(cas = 1;cas <= tst;cas++)
    {
        sc2ll(n,r);
        if(r == 1)
        {
            pf("Case %lld: %lld\n",cas,n*n);
            continue;
        }
        else if(r > n)
        {
            pf("Case %lld: 0\n",cas);
            continue;
        }
        else if(r == 0)
        {
            pf("Case %lld: 1\n",cas);
        }
        else
        {
            ull p = per(n,r);
            ull c = com(n,r);
            ull ans = p * c;
            pf("Case %lld: %llu\n",cas,ans);
        }
    }
    return 0;
}
