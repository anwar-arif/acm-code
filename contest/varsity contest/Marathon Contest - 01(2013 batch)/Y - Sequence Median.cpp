#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define LL long long
#define pb push_back

int main()
{
        int n,i,x,y,a,b;
        double ans;
        sc("%d",&n);
        priority_queue < int > q;
        if(n % 2 == 0)
        {
                for(i = 1; i <= (n/2) + 1; i++)
                {
                        sc("%d",&x);
                        q.push(x);
                }
                for(i = (n/2) + 1 ;i < n; i++)
                {
                        sc("%d",&x);
                        q.push(x);
                        q.pop();
                }

                a = q.top(); q.pop();
                b = q.top();
                ans = ( (double) a + (double) b)/ 2.0 ;
                pf("%0.1lf",ans);
        }
        else
        {
                for(i = 1; i <= (n/2) + 1; i++)
                {
                        sc("%d",&x);
                        q.push(x);
                }

                for(i = (n/2) + 1 ;i < n; i++)
                {
                        sc("%d",&x);
                        q.push(x);
                        q.pop();
                }

                ans = double (q.top());
                pf("%0.1lf\n",ans);
        }
        return 0;

}
