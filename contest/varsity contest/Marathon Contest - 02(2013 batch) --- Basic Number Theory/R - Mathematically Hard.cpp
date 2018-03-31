#include <bits/stdc++.h>
using namespace std;

#define pf        printf
#define sc        scanf
#define pb        push_back
#define mx        5000000
#define LLI       long long int
typedef unsigned long long int LL;
int phi[mx+5];
LL ans[mx+9];

void cal_phi()
{
        int i,j;
        phi[1] = 1;
        ans[1] = 0;

        for(i = 2; i <= mx; i++)
        {
                if(phi[i] == 0)
                {
                        for(j = i; j <= mx; j += i)
                        {
                                if(phi[j] == 0)
                                {
                                        phi[j] = j;
                                }

                                phi[j] = (phi[j] / i) * (i - 1);
                        }
                }
        }

        for(i = 2 ;i <= mx;i++)
        {
                ans[i] = phi[i];
                ans[i] *= phi[i];
                ans[i] += ans[i-1];
        }
}

int main()
{
        int tst,i,a,b;
        cal_phi();
        sc("%d",&tst);
        for(i = 1;i <= tst;i ++)
        {
                sc("%d %d",&a,&b);

                pf("Case %d: %llu\n",i, ans[b] - ans[a-1]);
        }
        return 0;
}
