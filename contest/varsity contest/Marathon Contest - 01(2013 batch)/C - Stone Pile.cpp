#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        int i,j,n,x,mn,a[50];
        while(sc("%d",&n) == 1)
        {
                for(i=0;i<n;i++)
                {
                        sc("%d",&a[i]);
                }
                mn = 99999999;
                for(i=0;i<n-1;i++)
                {

                                x = a[i] - a[i+1];
                                if(x<0)x=x*(-1);
                                if(x<mn)mn=x;
                }
                pf("%d\n",mn);
        }
        return 0;
}
