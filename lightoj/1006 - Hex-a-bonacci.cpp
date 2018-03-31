#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define LL long long

int main()
{
        LL int tst,i,j,n;
        sc("%lld",&tst);
        for(i=1;i<=tst;i++)
        {
                LL int ar[10005];
                for(j=0;j<6;j++)
                {
                        sc("%lld",&ar[j]);
                }
                sc("%lld",&n);
                for(j=6;j<=n;j++)
                {
                        ar[j]=(ar[j-6]+ar[j-5]+ar[j-4]+ar[j-3]+ar[j-2]+ar[j-1])%10000007;
                }

                pf("Case %lld: %lld\n",i,( ar[n] )%10000007);
        }
        return 0;
}
