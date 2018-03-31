#include <bits/stdc++.h>
using namespace std ;
#define pf printf
#define sc scanf
#define pb push_back

int rec(int hi,int lo,int x,int *s)
{
        int ans;
        int mid = (hi+lo) / 2;
        if(s[ mid ] == x)return mid;
        if(lo > hi)return -1;
        if(x < s[mid])ans = rec(mid-1,lo,x,s);
        if(x > s[mid])ans = rec(hi,mid+1,x,s);
        return ans;
}

int main()
{
        int n,i,a[100],q,j,x,ans,hi,lo,mid;
        while(sc("%d",&n) == 1)
        {
                for(i = 1;  i <= n ;i++)
                {
                        sc("%d",&a[i]);
                }
                sc("%d",&q);
                for(i = 1;  i <= q; i++)
                {
                        sc("%d",&x);
                        mid = (1+n)/2;
                        ans = rec(hi,lo,x,a);
                        if(ans == -1)pf("not found\n");
                        else pf("%d\n",ans);
                }
        }
        return 0;
}
