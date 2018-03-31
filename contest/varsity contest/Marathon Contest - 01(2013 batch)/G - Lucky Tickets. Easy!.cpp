#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define LL long long
#define pb push_back

int cal(int N)
{
        int a[50],st,i,n,sr,k,l,s2,s1,cnt;
        cnt = 0;sr = 0;
        for(st =  1; st <= N; st ++)
        {
                n = st; i = 0;
                while(n>=1)
                {
                        a[++i] = n % 10;
                        n /= 10;
                }

                if(i % 2 == 1)continue;
                s1 = s2 = 0;

                for(k = 1,l = i; k <= i/2 ; k++,l--)
                {
                        s1 += a[k];
                        s2 += a[l];
                }
                if(s1 == s2){++cnt;pf("n is %d sr is %d\n",st,++sr);}
        }
        return cnt;
}

int main()
{
        int n,x,ans;
        while(sc("%d",&n)==1) {

        if(n == 2)
        {
            ans = cal(99) + 1;
        }

        if(n == 4){ans = cal(9999);}
        pf("ans is %d\n",ans);
        }
        return 0;
}
