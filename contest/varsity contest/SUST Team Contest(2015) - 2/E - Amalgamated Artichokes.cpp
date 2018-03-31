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

int main()
{
    int i;
    double p,a,b,c,d,n,ans,mn,mx,x,dif;
    while(sc("%lf%lf%lf%lf%lf%lf",&p,&a,&b,&c,&d,&n) == 6)
    {
        mn = 99999999999999.0;
        mx = -99999999999999.0;
        ans = 0.0;
        for(i = 1; i<= n;i++){
            x = p*(sin(a*(double)i+b)+cos(c*(double)i+d)+2.0);
            if(x>mx){
                mx = x;
            }
            else{
                if(i>1){
                    dif = mx - x;
                    if(dif>ans)ans = dif;
                }
            }
        }
        pf("%0.9lf\n",ans);
    }
    return 0;
}
