#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define sc1ll(a) sc("%I64d",&a)
#define sc2ll(a,b) sc("%I64d%I64d",&a,&b)
#define sc3ll(a,b,c) sc("%I64d%I64d%I64d",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define pi acos(-1)
#define mod 100000007
#define inf 1<<28

int main()
{
        int tst,i,cas,len,j,t;
        char str[25];
        sc1i(tst);
        for(cas = 1;cas<= tst;cas++){
                scanf("%s",str);
                len = strlen(str);
                t = 1;i = 0;j = len - 1;
                while(i <= j){
                        if(str[i] != str[j]){
                                t = 0;break;
                        }
                        i++;j--;
                }
                if(t)pf("Case %d: Yes\n",cas);
                else pf("Case %d: No\n",cas);
        }
        return 0;
}
