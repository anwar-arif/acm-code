#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)

int main()
{
        int tst,cas,n,m,i,j,x,y,d;
        char ch;
        sc1i(tst);
        for(cas = 1;cas <= tst;cas++)
        {
                sc2i(n,m);
                int a[100];
                for(i = 0; i < n;i++){
                        sc("%d",&a[i]);
                }
                for(j = 1;j<=m;j++)
                {
                        getchar();
                        sc("%c",&ch);
                        if(ch == 'S')
                        {
                                sc1i(d);
                                for(i = 0;i <n ;i++)
                                {
                                        a[i]+= d;
                                }
                                continue;
                        }
                        if(ch == 'M'){
                                sc1i(d);
                                for(i = 0;i < n; i++){
                                        a[i] *= d;
                                }
                                continue;
                        }
                        if(ch == 'D'){
                                sc1i(d);
                                for(i = 0; i<n; i++){
                                        a[i] /= d;
                                }
                                continue;
                        }
                        if(ch == 'R'){
                                reverse(a,a+n);
                                continue;
                        }
                        if(ch == 'P'){
                                sc2i(x,y);
                                swap(a[x],a[y]);
                                continue;
                        }
                }
                pf("Case %d:\n",cas);
                pf("%d",a[0]);
                for(i = 1; i<n; i++){
                        pf(" %d",a[i]);
                }
                pf("\n");
        }
        return 0;
}
