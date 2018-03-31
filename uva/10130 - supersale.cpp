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

int dp[1001][31],cost[1001],weight[1001],c,obj;

int rec(int i,int w)
{
        if(i == obj+1)return 0;
        if(dp[i][w] != -1)return dp[i][w];
        int pr1 = 0;int pr2 = 0;
        if(w + weight[i] <= c){
                pr1 = cost[i] + rec(i + 1, w + weight[i]);
        }
        pr2 = rec(i + 1, w);
        dp[i][w] = max(pr1,pr2);
        return dp[i][w];
}

int main()
{
        int tst,i,g,sum;
        sc1i(tst);
        while(tst--){
                sc1i(obj);
                for(i = 1; i <= obj;i++){
                        sc2i(cost[i],weight[i]);
                }
                sc1i(g);
                sum = 0;
                for(i = 1; i <= g;i++){
                        sc1i(c);
                        memset(dp,-1,sizeof(dp));
                        sum += rec(1,0);
                }
                pf("%d\n",sum);
        }
        return 0;
}
