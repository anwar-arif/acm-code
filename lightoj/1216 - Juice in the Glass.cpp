#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>
#include <iomanip>
#include <bitset>
using namespace std;

#define pf printf
#define sc scanf
#define pb push_back
#define ll long long int
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sz(a) (int)a.size()
#define pi acos(-1)

int main()
{
        int tst,cas,r1,r,h,p;
        sc1i(tst);
        for(cas = 1;cas<= tst;cas++)
        {
                sc4i(r1,r,h,p);
                double R = r + (r1 - r)*(double(p)/h);
                double V = (1/3.0) * pi * p * (R*R + R*r + r*r);
                pf("Case %d: %lf\n",cas,V);
        }
        return 0;
}
