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
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define pi acos(-1.0)
#define inf 9999999999

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

int a[505],dp[505][505],n,k;

int rec(int i,int st)
{
    if(i == n+1)
    {
        if(st == k+1)return 0;
        return inf;
    }
    if(i > n or st > k)return inf;
    if(dp[i][st] != -1)return dp[i][st];
    int b,w,sum,j;
    b = w = 0;
    sum = inf;
    for(j = i ; j<=n;j++)
    {
        if(a[j] == 1)++b;
        else ++w;
        sum = min(sum,rec(j+1,st+1)+(b*w));
    }
    return dp[i][st] = sum;
}

int main()
{

    int i,ans;
    while(sc2i(n,k) != EOF)
    {
        memset(dp,-1,sizeof(dp));
        for(i = 1; i<= n;i++)
        {
            sc1i(a[i]);
        }
        ans = rec(1,1);
        pf("%d\n",ans);
    }
    return 0;
}
