#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long
#define mx 2147483648



int main()
{
        LL int i,s,n,x;
        map<long long,long long >mp;
        s=1;
        for(i=1;;i++)
        {
                mp[s] = 1;
                s = s + i;
                if(s >= mx)break;
        }

               sc("%lld",&n) ;

                for(i=1;i<=n;i++)
                {
                        sc("%lld",&x);
                        if(mp[x] == 1)pf("1 ");
                        else pf("0 ");
                }

        return 0;
}
