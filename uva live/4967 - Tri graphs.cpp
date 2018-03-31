#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)
#define pi acos(-1)
#define inf 999999999999

ll n,a[100009][5],ans,dp[100009][5];
ll dx[] = {1,1,1,0};
ll dy[] = {0,-1,1,1};

bool valid(ll i,ll j)
{
    if(i > n || j > 3 || j < 1)return false;
    return true;
}

ll rec(ll  i,ll  j)
{
    if(dp[i][j]!= -1){
        return dp[i][j];
    }
    if(i > n || j > 3 || j < 1)return inf;
    if(i == n and j == 2)return a[i][j];

    ll  p = inf;
    ll  k,x,y;

    for(k = 0;k<4;k++){
        x = i + dx[k];
        y = j + dy[k];
        if(valid(x,y))
        {
            p = min(p , a[i][j]+rec(x,y));
        }
    }
    return dp[i][j] = p;
}
int main()
{
    ll  cas = 0;
    while(sc1ll(n) && n){
        for(ll  i = 1; i <= n;i++){
            for(ll  j = 1; j <= 3; j++){
                sc1ll(a[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        rec(1,2);
        pf("%lld. %lld\n",++cas,dp[1][2]);
    }
    return 0;
}
