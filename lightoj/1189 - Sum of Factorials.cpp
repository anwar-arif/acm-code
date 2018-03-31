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
#define ull unsigned long long int

ull a[20];

void cal()
{
        a[0] = (ull)1;
        for(int i = 1;i < 21;i++){
                a[i] = a[i-1]*i;
        }
}

int main()
{
        int tst,cas,k,b[21],i;
        ull n;
        cal();
        sc1ll(tst);
        for(cas = 1; cas <= tst;cas++){
                sc("%llu",&n);
                k = 0;
                for(i = 20;i>= 0;i--){
                        if(a[i] <= n){
                                b[++k] = i;
                                n -= a[i];
                        }
                }
                if(n == 0){
                        sort(b+1,b+k+1);
                        pf("Case %d: %d!",cas,b[1]);
                        for(i = 2; i <= k;i++){
                                pf("+%d!",b[i]);
                        }
                        pf("\n");

                }else{
                      pf("Case %d: impossible\n",cas);
                }
        }
        return 0;
}
