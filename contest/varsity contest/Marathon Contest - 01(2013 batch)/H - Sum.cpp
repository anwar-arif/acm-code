#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        int n,x;
        while(sc("%d",&n) == 1)
        {
                if(n>0)
                {
                        pf("%d\n",(n*(n+1)/2));
                }
                else if(n<0)
                {
                        n=n*(-1);
                        x=((n*(n+1)/2)-1)*(-1);
                        pf("%d\n",x);
                }
                else if(n == 0)pf("1\n");
        }
        return 0;
}
