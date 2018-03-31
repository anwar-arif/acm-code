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

//#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define ll long long int
#define pb push_back
#define pi acos(-1.0)
#define mem(a,val) memset(a,val,sizeof(a))

int main()
{
    int n,i,j,x,res[105],deg[105],connected[105][105],cnt;
    sc1i(n);
    mem(deg,0);
    mem(connected,0);
    queue<int>q;
    for(i = 1; i<= n;i++)
    {
        while(sc1i(x))
        {
            if(x == 0)break;
            connected[i][x] = 1;
            ++deg[x];
        }
    }
    for(i = 1;i <= n; i++)
    {
        if(deg[i] == 0)q.push(i);
    }
    cnt = 0;
    while(!q.empty())
    {
        x = res[++cnt] = q.front();q.pop();
        //pf("%d ",x);
        for(i = 1; i <= n;i++)
        {
            if(connected[x][i] == 1)
            {
                --deg[i];
                if(deg[i] == 0){q.push(i);}
            }
        }
    }
    for(i = 1 ; i <= cnt;i++)
    {
        pf("%d ",res[i]);
    }
    pf("\n");
    return 0;
}
