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

ll dp[501][501];

ll rec(ll pre,ll remain)
{
        if(remain == 0)return 1;
        if(remain <= pre)return 0;
        if(dp[pre][remain] != -1)return dp[pre][remain];
        ll ret = 0;
        for(ll i = pre+1; i <= remain;i++){
                ret += rec(i,remain-i);
        }
        return dp[pre][remain] = ret;
}

int main()
{
        ll n,s,i,j,x,a,b,k;
        while(sc1ll(n) ==1){
                for(i = 0;i<=500;i++){
                        for(j = 0;j<=500;j++){
                                dp[i][j] = -1;
                        }
                }
                s = rec(0,n);
                pf("%lld\n",s-1);
        }
        return 0;
}
