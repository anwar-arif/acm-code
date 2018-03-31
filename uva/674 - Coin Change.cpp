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

int coin[] = {1,5,10,25,50};
int dp[6][7490];

int rec(int i,int amount)
{
        if(i >= 5){
                if(amount == 0)return 1;
                return 0;
        }
        if(dp[i][amount] != -1)return dp[i][amount];
        int p1 = 0,p2 = 0;
        if(amount - coin[i] >= 0){
                p1 = rec(i,amount - coin[i]);
        }
        p2 = rec(i+1,amount);
        return dp[i][amount] = (p1 + p2);
}

int main()
{
        int value,ans;
        memset(dp,-1,sizeof(dp));
        while(sc1i(value) == 1){
                        if(value == 0){pf("1\n");continue;}
                ans = rec(0,value);
                pf("%d\n",ans);
        }
        return 0;
}
