#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        int h,l,j,t,x,y;
        while(sc("%d %d",&h,&l) == 2)
        {
                if(h == 0 || l == 0)
                {
                        if(h == 0)
                        {
                                h = l;
                                l = 0;
                                pf("%d %d\n",h,l);continue;
                        }
                        if(l == 0)
                        {
                                l = h;
                                h = 0;
                                pf("%d %d\n",h,l);continue;
                        }

                }
                x = (h + l) -1;
                pf("%d %d\n",x - h, x - l);
        }
        return 0;
}
