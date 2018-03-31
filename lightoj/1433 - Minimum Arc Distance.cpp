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
#define mx 100005

int main()
{
        int tst,ox,oy,ax,ay,bx,by,i;
        double ang,r,ab;
        sc1i(tst);
        for(i = 1; i<= tst;i++)
        {
                sc4i(ox,oy,ax,ay);
                sc2i(bx,by);
                r = sqrt( ((ox - ax)*(ox - ax)) + ( (oy - ay)*(oy - ay) ) );
                ab = sqrt( ((ax - bx)*(ax - bx)) + ( (ay - by)*(ay - by) ) );
                ang = acos( 1 - 0.5 *(ab/r)*(ab/r) );
                pf("Case %d: %0.8lf\n",i,ang*r);
        }
        return 0;
}
