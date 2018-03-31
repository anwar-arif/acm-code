#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int main()
{
        int a,b,c,d,m,v;
        while(sc("%d %d %d %d", &a, &b, &c, &d) == 4)
        {
                m = max( ( (3*a)/ 10) , (a - (a * c) / 250) );
                v = max( ( (3*b)/ 10) , (b - (b * d) / 250) );
                if(m>v){pf("Misha\n");}
                if(m<v){pf("Vasya\n");}
                else if(m == v)
                {
                        pf("Tie\n");
                }
        }
        return 0;
}
