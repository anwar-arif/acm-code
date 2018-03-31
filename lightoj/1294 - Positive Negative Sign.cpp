#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int main()
{
        long long int tst,cas,a,b;
        sc("%lld",&tst);
        for(cas = 1; cas <= tst;cas++)
        {
                sc("%lld%lld",&a,&b);
                pf("Case %lld: %lld\n",cas,(a*b)/2);
        }
        return 0;
}
