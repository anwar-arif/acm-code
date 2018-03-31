#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        LL int a,b,i,cnt,x,y;
        while(sc("%lld %lld",&a,&b) == 2)
        {
                if(b == 1){ pf("%lld\n",a); continue; }

                if(b == 2)
                {
                        if(a % b == 0){pf("%lld\n",a/2);continue;}
                        else
                        {
                                pf("%lld\n",(a/2) + 2); continue;
                        }

                }
                cnt = 0;
                for(i = 1; ; i++)
                {
                        if(a > b)
                        {
                                x = a % b;
                                y = a / b;
                                a = a % b; cnt += y;
                                if(x == 0){break;}
                                continue;
                        }
                        if(a < b)
                        {
                                x = b % a;
                                y = b / a;
                                b = b % a; cnt += y;
                                if(x == 0){break;}
                                continue;
                        }
                }
                pf("%lld\n",cnt);
        }
        return 0;
}

