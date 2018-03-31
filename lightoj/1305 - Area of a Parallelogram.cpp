#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)

int main()
{
        int ax,ay,bx,by,cx,cy,dx,dy,tst,cas;
        sc("%d",&tst);
        for(cas = 1; cas <= tst;cas++)
        {
                sc("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);

                dx = cx - (bx - ax);
                dy = cy - (by - ay);

                double a = sqrt( ( (ax - bx) * (ax - bx) ) + ( (ay - by) * (ay - by) ) );
                double b = sqrt( ( (ax - cx) * (ax - cx) ) + ( (ay - cy) * (ay - cy) ) );
                double c = sqrt( ( (ax - dx) * (ax - dx) ) + ( (ay - dy) * (ay - dy) ) );

                double s = (a + b + c)/2.0;

                double ar = 2 * (sqrt(s*(s-a)*(s-b)*(s-c)));

                pf("Case %d: %d %d %.0lf\n",cas,dx,dy,ar);
        }
        return 0;
}
