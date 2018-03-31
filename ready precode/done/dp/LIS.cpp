#include <bits/stdc++.h>
using namespace std;

int dp[100],dir[100],val[100],n;

int longest(int u)
{
    if(dp[u] != -1)return dp[u];

    int maxi = 0;

    for(int v = u+1 ; v <= n; v++)
    {
        if(val[v] > val[u])
        {
            int x = longest(v);
            if(x > maxi)
            {
                maxi = x;
                dir[u] = v;
            }
        }
    }

    dp[u] = maxi+1;

    return dp[u];
}

int main()
{
    int n,i,x,lis,start;
    while(sc1i(n) == 1)
    {
        for(i = 1; i<= n; i++)
        {
            sc1i(val[i]);
        }

        mem(dp,-1);
        mem(dir,-1);

        lis = 0;
        start;

        for(i = 1; i<= n; i++)
        {
            x = longest(i);

            pf("longest path from %d is %d\n",i,x);

            if(x > lis)
            {
                lis = x;
                start = i;
            }
        }

        pf("LIS %d starting point %d\n",lis,start);
    }

    return 0;
}
complexity :
n^2;
