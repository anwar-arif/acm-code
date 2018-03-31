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

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define For(i,a,b) for(i=a;i<=b;i++)
#define pi acos(-1)

int main()
{
    int tst;
    double w,H,x,xe,ye,u,t1,t2,h,theta_1,y,x1;
    sc1i(tst);
    while(tst--)
    {
        sc("%lf%lf%lf%lf%lf%lf",&w,&H,&x,&xe,&ye,&u);

        theta_1 = atan((xe-w)/(y-H));

        t2 = tan( asin( ( sin( theta_1 ) / u ) ) );

        t1 = tan(theta_1);

        x1 = ((-H*(w-xe))/(H-ye)) + w;

        h = (x - x1)/(t1 - t2);

//        pf("x1 = %0.3lf x = %0.3lf\n",x1,x);
        if(h > H)
        {
            pf("Impossible\n");
        }
        else if(x1 < x)
        {
            pf("0.00\n");
        }
        else
        {
            pf("%0.6lf\n",h);
        }
    }
}
