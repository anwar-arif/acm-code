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
#define sc1ll(a) sc("%I64d",&a)
#define sc2ll(a,b) sc("%I64d%I64d",&a,&b)
#define sc3ll(a,b,c) sc("%I64d%I64d%I64d",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define For(i,a,b) for(i=a;i<=b;i++)
#define pi acos(-1)

int main()
{
    ll a[65],cas=0,n;
    int i;
    a[1] = a[2] = a[3] = 1;
    for(i = 4;i<= 61;i++){
        a[i] = a[i-1]+a[i-2]+a[i-3];
        //pf("%lld\n",a[i]);
    }
    while(sc1ll(n) == 1){
        if(n == 0)return 0;
        pf("Case %lld: %lld\n",++cas,a[n]);
    }
}
