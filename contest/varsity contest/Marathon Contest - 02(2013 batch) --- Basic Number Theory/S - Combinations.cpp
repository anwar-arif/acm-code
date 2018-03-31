#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

long long int nPr(long long n,long long r)
{
        long long int res=1,i;
        for(i=1;i<=r;i++,n--)
        {
                res*=n;
        }
        return res/2;
}

int main()
{
        long long int cas,i,n,r,ans;
        sc("%lld",&cas);
        for(i=1;i<=cas;i++)
        {
                sc("%lld%lld",&n,&r);
                if(n<r){pf("Case %lld: 0\n",i);continue;}
                if(n==0 || r==0){pf("Case %lld: 1\n",i);continue;}
                ans=nPr(n,r)%1000003;
                pf("Case %lld: %lld\n",i,ans);
        }
        return 0;
}
