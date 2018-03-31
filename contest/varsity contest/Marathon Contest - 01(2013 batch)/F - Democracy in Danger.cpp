#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        int n,i,s,a[105];
        while(sc("%d",&n) == 1)
        {
                for(i=0;i<n;i++)
                {
                        sc("%d",&a[i]);
                }
                sort(a,a+n);
                s = 0;
                for(i=0;i<=(n/2);i++)
                {
                        s += (a[i]/2)+1;
                }
                pf("%d\n",s);
        }
        return 0;
}
