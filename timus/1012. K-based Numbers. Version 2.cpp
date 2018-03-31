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

ll dp[11][1801],n,k;

ll rec(ll cur,ll cnt)
{
        if(cnt == n){if(cur == 0)return 0;return 1;}
        if(cnt > n)return 0;
        if(dp[cur][cnt] != -1)return dp[cur][cnt];
        ll s = 0;ll st = 0;
        if(cur == 0)st = 1;
        for(ll i = st;i<k;i++){
                s += rec(i,cnt+1);
        }
        return dp[cur][cnt] = s;
}

int main()
{
        ll ans,i;
        while(sc2ll(n,k) == 2){
                memset(dp,-1,sizeof(dp));
                ans = 0;
                ans += rec(1,0);
                pf("%lld\n",ans);
        }
        return 0;
}

