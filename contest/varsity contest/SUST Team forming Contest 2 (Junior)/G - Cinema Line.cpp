#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define pi acos(-1)

int main()
{
    int t25,t50,t100,n,i,a[100009],t;
    while(sc1i(n) != EOF)
    {
        for(i = 1; i<= n;i++)
        {
            sc1i(a[i]);
        }
        t = 1;
        t25 = t50 = t100 = 0;
        for(i = 1; i<= n;i++)
        {
            if(a[i] == 25)
            {
                ++t25;
            }
            else if(a[i] == 50)
            {
                if(t25 == 0){
                    t = 0;break;
                }
                else
                {
                    --t25;++t50;
                }
            }
            else if(a[i] == 100)
            {

                if(t25 >= 1 and t50 >= 1)
                {
                    --t25;--t50;
                    ++t100;
                }
                else if(t25 >= 3)
                {
                    ++t100;
                    t25 -= 3;
                }
                else{
                    t = 0;break;
                }
            }
        }
        if(t){
            pf("YES\n");
        }else{
            pf("NO\n");
        }
    }
}
