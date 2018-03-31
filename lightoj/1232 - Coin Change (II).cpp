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
#define mod 100000007
#define inf 1<<28

int sum[10001],coin[101],n,k;

int rec(int k)
{
        sum[0] = 1;
        for(int i = 1;i <= n;i++){
                for(int j = coin[i];j <= k;j++){
                        sum[j] = (sum[j]+sum[j-coin[i]])%mod;
                }
        }
        return sum[k];
}

int main()
{
        int tst,cas,ans,i;
        sc1i(tst);
        for(cas = 1;cas <= tst;cas++){
                sc2i(n,k);
                memset(sum,0,sizeof(sum));
                for(i = 1;i<= n;i++){
                        sc1i(coin[i]);
                }
                ans = rec(k);
                pf("Case %d: %d\n",cas,ans);
        }
        return 0;
}
