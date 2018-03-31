#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        int n,i,t,cheack[500],k;
        char ch,a[5000];
        while(sc("%d",&n) == 1)
        {
                getchar();
                gets(a);
                t = 1;
                for(i=0;i<n;i++)
                {
                        ch = toupper(a[i]);
                        k = ch - 64;
                        ++cheack[k];
                }
                for(i=1;i<=26;i++)
                {
                        if(cheack[i] == 0)
                        {
                                t = 0;break;
                        }
                }
                if(t == 1)
                {
                        pf("YES\n");
                }
                else
                {
                        pf("NO\n");
                }
                memset(cheack,0,sizeof(cheack));
        }
        return 0;
}
