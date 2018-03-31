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

int n,dp[21][4],a[21][4];

int rec(int r,int c)
{
        if(r >= 1 && r <= n && c >= 1 && c <=3)
        {
                if(dp[r][c] != -1)return dp[r][c];
                int p;
                p = inf;
                if(c == 1){
                        p = min(p,rec(r+1,c+1)+a[r][c]);
                        p = min(p,rec(r+1,c+2)+a[r][c]);
                }
                if(c == 2){
                        p = min(p,rec(r+1,c+1)+a[r][c]);
                        p = min(p,rec(r+1,c-1)+a[r][c]);
                }
                if(c == 3){
                        p = min(p,rec(r+1,c-1)+a[r][c]);
                        p = min(p,rec(r+1,c-2)+a[r][c]);
                }
                return dp[r][c] = p;
        }
        return 0;
}

int main()
{
        int tst,cas,i,res,j,ans;
        sc1i(tst);
        for(cas = 1; cas <= tst;cas++){
                sc1i(n);
                memset(dp,-1,sizeof(dp));
                for(i = 1; i <= n;i++){
                        sc3i(a[i][1],a[i][2],a[i][3]);
                }
                res = inf;
                for(i = 1;i<=3;i++){
                        ans = rec(1,i);
                        res = min(ans,res);
                }
                pf("Case %d: %d\n",cas,res);
        }
        return 0;
}
