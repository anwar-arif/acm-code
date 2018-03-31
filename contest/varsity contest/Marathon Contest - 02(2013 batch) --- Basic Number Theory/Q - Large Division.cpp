#include <bits/stdc++.h>
using namespace std;

#define pf        printf
#define sc        scanf
#define pb        push_back
#define mx        5000000
#define LLI       long long int
#define LL        long long

int main()
{
        LL int tst,cas,i,n,r,x,len;
        char a[15000];
        sc("%lld",&tst);
        for(cas = 1; cas <= tst; cas++)
        {
                //getchar();
                sc("%s %lld",&a,&n);
                if(n<0){n = n * (-1);}

                len = strlen(a);

                if(a[0] == '-')
                {
                        r = 0;
                        for(i = 1 ; i < len; i++)
                        {
                                r *= 10;
                                r = r + (a[i] - '0');
                                r = r % n;
                        }
                        if(r == 0)
                        {
                               pf("Case %lld: divisible\n",cas);
                        }
                        else
                        {
                                pf("Case %lld: not divisible\n",cas);
                        }
                }
                else
                {
                        r = 0;
                        for(i = 0 ;i < len; i++)
                        {
                                r *= 10;
                                r = r + (a[i] - '0');
                                r = r % n;

                        }
                        if(r == 0)
                        {
                                pf("Case %lld: divisible\n",cas);
                        }
                        else
                        {
                               pf("Case %lld: not divisible\n",cas);
                        }
                }
        }
        return 0;
}
