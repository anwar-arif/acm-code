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

int coin[51],c[51],k,dp[51][1001],n;

int rec(int i,int amount)
{
        if(i > n){
                if(amount == k)return 1;
                return 0;
        }
        if(amount > k)return 0;
        if(amount == k)return 1;
        if(dp[i][amount] != -1)return dp[i][amount];
        int p = 0;
        for(int j = 1;j<=c[i];j++){
                if(amount+(coin[i]*j) <= k){
                       p += rec(i+1,amount+(coin[i]*j))%mod;
                }
                else break;
        }
        p += rec(i+1,amount)%mod;
        return dp[i][amount] = p%mod;
}

int main()
{
        int tst,cas,i;
        sc1i(tst);
        for(cas = 1; cas <= tst;cas++){
                sc2i(n,k);
                memset(dp,-1,sizeof(dp));
                for(i = 1;i <= n;i++){
                        sc1i(coin[i]);
                }
                for(i = 1;i <= n;i++){
                        sc1i(c[i]);
                }
                pf("Case %d: %d\n",cas,rec(1,0)%mod);
        }
        return 0;
}
