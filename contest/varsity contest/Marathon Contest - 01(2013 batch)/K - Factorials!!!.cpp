#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        LL int n,len,s;
        char a[500];
        while(sc("%lld",&n) == 1)
        {
                getchar();
                gets(a);
                len = (int)strlen(a);
                s = 1;
                while(n > 1)
                {
                        s = s * n;
                        n = n - len;
                }
                pf("%lld\n",s);
        }
        return 0;
}
