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

int dp[201][201],n,a[201][201];

int rec(int r,int c)
{
        if(c == 0 || r >= (2*n))return 0;
        if(dp[r][c] != -1)return dp[r][c];
        int p;
        if(r >= n){
                if( 1 < c && c <(n-(r-n))){
                                p = -inf;
                        p = max(p,rec(r+1,c-1)+a[r][c]);
                        p = max(p,rec(r+1,c)+a[r][c]);
                }else{
                      if(c == 1){
                              p = -inf;
                        p = max(p,rec(r+1,c)+a[r][c]);
                      }else if(c == (n-(r-n))){
                              p = -inf;
                            p = max(p,rec(r+1,c-1)+a[r][c]);
                      }
                }
        }
        else{
                p = -inf;
                p = max(p,rec(r+1,c)+a[r][c]);
                p = max(p,rec(r+1,c+1)+a[r][c]);
        }
        return dp[r][c] = p;
}

int main()
{
        int tst,cas,i,j,ans;
        sc1i(tst);
        for(cas = 1; cas <= tst;cas++){
                sc1i(n);
                memset(dp,-1,sizeof(dp));
                for(i = 1; i <= n;i++){
                        for(j = 1; j<=i;j++){
                                sc1i(a[i][j]);
                        }
                }
                for(i = n+1; i <= (2*n) - 1; i++){
                        for(j = 1; j <= (2*n) - i ;j++){
                                sc1i(a[i][j]);
                        }
                }
                ans = rec(1,1);
                pf("Case %d: %d\n",cas,ans);
        }
        return 0;
}
