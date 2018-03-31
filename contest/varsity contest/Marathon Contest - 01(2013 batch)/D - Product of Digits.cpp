#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long
#define mx 2147489
#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

int main()
{
        int n,i,N,k,a[500],s;
        while(sc("%d",&n) == 1)
        {
                if(n == 0){pf("10\n");continue;}
                if(n<10){pf("%d\n",n);continue;}

                N = n; k = 0;
                for(i  = 9 ; i>=2 ; i --)
                {
                        if(n % i == 0)
                        {
                                while(n % i == 0)
                                {
                                        a[++k] = i;
                                        n = n / i;
                                }
                        }
                }

                s = 1;
                for(i = 1; i <= k ;i++)
                {
                        s = s * a[i];
                }

                if(s != N)
                {
                        pf("-1\n");continue;
                }
                for(i = k ; i>=1 ; i--)
                {
                        pf("%d",a[i]);
                }
                pf("\n");
        }
        return 0;
}
