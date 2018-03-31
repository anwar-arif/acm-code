#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long
#define MAX 100000
int a[MAX+5];
int s[MAX+5];
void cal()
{
        int i,mx;
        a[0] = 0;
        a[1] = 1; s[1] = 1;
        mx = 1;
        for(i = 2;i <= MAX; i++)
        {
                if(i%2 == 0)
                {
                        a[i] = a[i/2];
                        if(mx < a[i]) mx = a[i];

                        s[i] = mx;
                }
                else
                {
                        a[i] = a[i/2] + a[(i/2)+1];
                        if(mx < a[i]){mx = a[i];}
                        s[i] = mx;
                }
        }
}

int main()
{
        int n;
        cal();
        while(sc("%d",&n) == 1)
        {
                if(n == 0)break;
                pf("%d\n",s[n]);
        }
        return 0;
}

