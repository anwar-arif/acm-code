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

bool mark[31],counted[31];
int dp[31][1001],t[31],v[31],tres,total;

int rec(int cnt,int tim)
{
        if(cnt > tres)return 0;
        if(tim < 0)return 0;
        if(dp[cnt][tim] != -1)return dp[cnt][tim];

        int p1,p2;

        p1 = 0;p2 = 0;

        if(tim-t[cnt] >=0){
                p1 = rec(cnt+1,tim-t[cnt])+v[cnt];
        }

        p2 = rec(cnt+1,tim);

        mark[cnt] = ((p1>p2)|| mark[cnt]);

        if(mark[cnt]){
                if(!counted[cnt]){
                        counted[cnt] = true;
                        ++total;
                }
        }

        return dp[cnt][tim] = max(p1,p2);
}

void reset()
{
        int i,j;
        for(i = 0;i<31;i++){
                for(j = 0; j<1001;j++){
                        dp[i][j] = -1;
                }
                mark[i] = false;
                counted[i] = false;
        }
}

int main()
{
        int w,a,i,ans,time;
        while(sc2i(time,w) == 2)
        {
                sc1i(tres);
                reset();
                for(i =1;i<=tres;i++)
                {
                        sc2i(a,v[i]);
                        t[i] = (2*w*a)+(w*a);
                }
                total = 0;
                ans = rec(1,time-t[1]);
                pf("%d\n%d\n",ans,total);

        }
        return 0;
}
