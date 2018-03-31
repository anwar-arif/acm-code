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
        ll tst,cas,n,sq,low,high,col,row;
        sc1ll(tst);
        for(cas = 1; cas <= tst;cas++)
        {
                sc1ll(n);
                double sqr = sqrt(n);
                if((int)sqr * (int)sqr == n)//if n is a square number
                {
                        sq = (int)sqr;
                        if(sq % 2 == 0)
                        {
                                pf("Case %lld: %lld 1\n",cas,sq);continue;
                        }
                        else pf("Case %lld: 1 %lld\n",cas,sq);continue;
                }

                sq = (int)sqrt(n);
                low = sq * sq;
                high = (sq+1)*(sq+1);
                if(sq % 2 == 0)//if square root of n is even
                {
                        if(n > low && n<= (low+sq+1))
                        {
                                col = sq + 1;
                                row = n - low;
                        }
                        else
                        {
                                col = high - n + 1;
                                row = sq + 1;
                        }
                        pf("Case %lld: %lld %lld\n",cas,col,row);
                }

                else//if square root of n is odd
                {
                        if(n > low && n <= (low + sq + 1))
                        {
                                row = sq + 1;
                                col = n - low;
                        }
                        else
                        {
                                row = high - n + 1;
                                col = sq + 1;
                        }
                        pf("Case %lld: %lld %lld\n",cas,col,row);
                }
        }
        return 0;
}
