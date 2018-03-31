#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        LL int n,a,b;
        while(sc("%lld%lld%lld",&n,&a,&b) == 3)
        {
                pf("%lld\n",2*n*a*b);
        }
        return 0;
}
