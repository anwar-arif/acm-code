#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define pb push_back

int main()
{
        int x,y,n;
        while(sc("%d%d%d",&x,&y,&n)==3)
        {
                int c=abs(x);
                int d=abs(y);

                int t=c+d;

                if(t>n)pf("No\n");
                else if((t-n)%2==0)pf("Yes\n");
                else pf("No\n");
        }
        return 0;
}
