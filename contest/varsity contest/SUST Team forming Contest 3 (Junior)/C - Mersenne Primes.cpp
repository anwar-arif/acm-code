#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
#include <climits>
//#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define pi acos(-1.0)

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

int main()
{
    ll tst,n ;
    ll a[] = {0,1,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,
              4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,
              216091,756839,859433,1257787,1398269,2976221,3021377,6972593};

    sc1ll(tst);
    while(tst--)
    {
        sc1ll(n);
        pf("%lld\n",a[n+1]);
    }
    return 0;
}
