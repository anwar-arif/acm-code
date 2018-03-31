#include <bits/stdc++.h>
using namespace std;

#define pf        printf
#define sc        scanf
#define pb        push_back
#define mx        5000000
#define LLI       long long int

int main()
{
        int tst,cas,n,ans[110],i,a[110],j,cnt,k;
        sc("%d",&tst);

        for(cas = 1; cas <= tst; cas++)
        {
                sc("%d",&n);
                memset(ans,0,sizeof(ans));
                for(i = 1; i<=n; i++){a[i] = i;}

                for(i = 2; i <= n; i++)
                {

                        for(j = i ;j <= n ;j++)
                        {
                                cnt = 0; k = j;
                                if(a[k] % i == 0 && a[k] >1)
                                {
                                        while(a[k] % i == 0)
                                        {
                                                ++cnt;
                                                a[k] = a[k] / i;
                                                if(a[k] == 1)break;
                                        }

                                        if(a[k] == 1){a[k] = 0;}
                                        ans[i] += cnt;
                                }
                        }
                }
                pf("Case %d: %d = ",cas,n);
                cnt = 0;
                for(i = 2; i <= n ;i++)
                {
                        if(ans[i] > 0)
                        {

                                if(cnt>0)
                                {
                                        pf(" * %d (%d)",i,ans[i]);
                                }
                                else pf("%d (%d)",i,ans[i]);
                                ++cnt;
                        }
                }
                pf("\n");
        }
        return 0;
}
