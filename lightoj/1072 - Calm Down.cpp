#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pi 3.1415926535897932385

int main()
{
        int tst,i,n;
        double R,ans,r;
        sc("%d",&tst);
        for(i=1;i<=tst;i++)
        {
                sc("%lf%d",&R,&n);
                ans=sin(pi/n);
                r=(ans*R)/(1+ans);
                pf("Case %d: %0.12lf\n",i,r);
        }
        return 0;
}
