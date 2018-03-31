#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int solve(int n, int m) {
    if (n > m) swap(n, m);
    if (n == 1) return m;
    if (n == 2)
        return (m / 4) * 4 + min((m % 4), 2) * 2;
    return (n * m + 1) >> 1;
}
int main()
{
         int cas,m,n,ans,i;
         sc("%d",&cas);
         for(i=1;i<=cas;i++)
         {
                 sc("%d%d",&m,&n);
                 ans=solve(m,n);
                 pf("Case %d: %d\n",i,ans);
         }
         return 0;
}
