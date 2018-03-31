#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int main()
{
        int f,x;
        while(sc("%d",&f) == 1)
        {
                x = (12-f)*45;
                if(x <= 240)pf("YES\n");
                else pf("NO\n");
        }
        return 0;
}
