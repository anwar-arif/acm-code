#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)

ll sol(ll n)
{
        ll res = 2 *(n / 3);
        if(n%3 == 2)res += 1;
        return res;
}

int main()
{
        ll tst,cas,a,b;
        sc1ll(tst);
        for(cas = 1;cas <= tst;cas++)
        {
                sc2ll(a,b);
                ll A,B;
                B = sol(b);
                if(a == 1)A = 0;
                else A = sol(a-1);
                ll ans = B - A ;
                pf("Case %lld: %lld\n",cas,ans);
        }
        return 0;
}
