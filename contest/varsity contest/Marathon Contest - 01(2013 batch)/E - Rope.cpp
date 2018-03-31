#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long
#define mx 10000000
#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))


int main()
{
        int n,i;
        double x[150],y[150],r,ans,d;
        while(sc("%d %lf",&n,&r) == 2)
        {
                for(i = 1; i <= n; i++)
                {
                        sc("%lf%lf",&x[i],&y[i]);
                }
                ans = 0.0;
                for( i = 1 ;i < n; i++)
                {

                        d = sqrt( ((x[i] - x[i+1]) * (x[i] - x[i+1])) + ((y[i] - y[i+1]) * (y[i] - y[i+1])) );
                        ans = ans + d;
                }

                d = sqrt((((x[1] - x[n]) * (x[1] - x[n])) + ((y[1] - y[n]) * (y[1] - y[n])) ) ) ;
                ans = ans + d;

                ans = ans + (2 * 3.1416 * r);

                pf("%0.2lf\n",ans);
        }
        return 0;
}
