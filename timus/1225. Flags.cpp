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
#define mx 10001

ll n,dp[4][46],pre2;

ll rec(ll pre,ll cnt)
{
        if(cnt > n)return 0;
        if(cnt == n){
                if(pre == 2)return 0;
                return 1;
        }
        if(dp[pre][cnt] != -1)return dp[pre][cnt];
        ll s = 0;
        if(pre == 1){
                s += rec(2,cnt+1);
                s += rec(3,cnt+1);
                pre2 = 1;
        }
        else if(pre == 2){
                if(pre2 == 3)s += rec(1,cnt+1);
                if(pre2 == 1)s += rec(3,cnt+1);
                pre2 = pre;
        }
        else if(pre == 3){
                s += rec(1,cnt+1);
                s += rec(2,cnt+1);
                pre2 = 3;
        }
        return dp[pre][cnt] = s;
}

int main()
{
        ll ans;
        while(sc1ll(n) == 1){
                memset(dp,-1,sizeof(dp));
                ans = 0;pre2 = 1;
                ans += rec(1,1);
                pre2 = 3;
                ans += rec(3,1);
                pf("%lld\n",ans);
        }
        return 0;
}
