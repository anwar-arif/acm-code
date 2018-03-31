#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>
using namespace std;

#define pf printf
#define sc scanf
#define LL long long
int main()
{
        LL int tst,i,a,b,c,d,e,f,g,h,j,k,l,m;
        char p[40],c1,c2,c3;
        double r;

        sc("%lld",&tst);
        for(i=1;i<=tst;i++)
        {
                sc("%lld%c%lld%c%lld%c%lld",&a, &c1, &b, &c2, &c, &c3, &d);
                getchar();

                gets(p);
                r=0;
                e=f=g=h=0;

                for(j=34,k=25,l=16,m=7;m>=0;j--,k--,l--,m--)
                {
                        e=e+  ( (p[j]-'0') *pow(2,r) );

                        f=f+  ( (p[k]-'0') *pow(2,r) );

                        g=g+  ( (p[l]-'0') *pow(2,r) );

                        h=h+  ( (p[m]-'0') *pow(2,r) );
                        ++r;
                }
                if(a==h && b==g && c==f && d==e)
                {
                        pf("Case %lld: Yes\n",i);
                }
                else
                {
                        pf("Case %lld: No\n",i);
                }
        }
        return 0;
}
