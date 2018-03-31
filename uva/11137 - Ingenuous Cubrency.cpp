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
#define pi acos(-1)

ll coin[22],res[10001];

void call()
{
        res[0] = 1;
        for(ll i = 1;i<= 21;i++){
                for(ll j = coin[i]; j <= 10000;j++){
                        res[j] = res[j]+res[j - coin[i]];
                }
        }
}

int main()
{
        ll i,n;
        for(i = 1;i<= 21;i++){
                coin[i] = i*i*i;
        }
        memset(res,0,sizeof(res));
        call();
        while(sc1i(n) == 1){
                pf("%lld\n",res[n]);
        }
        return 0;
}
