#include <bits/stdc++.h>
using namespace std;

#define SIZ 100+5

int row[SIZ],col[SIZ],dp[SIZ][SIZ];

int rec(int beg , int end)
{
    if(beg >= end)return 0;

    if(dp[ beg ][ end ] != -1)return dp[ beg ][ end ];

    int ans = p_inf;

    for(int mid = beg , mid < end ; mid++)
    {

        int lft = rec(beg , mid);

        int rt = rec( mid+1 , end);

        int extra = row[ beg ] * col[ mid ] * cod[ end ];

        int total = lft + rt + extra;

        ans = min(ans , total);
    }
    return dp[ beg ][ end ] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //Read;
    //Write;
#endif
    int n;
    sc1i(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin>>row[i]>>col[i];
    }

    cout<<rec(0,n-1)<<endl;

    return 0;
}
complexity = O(n^3)
