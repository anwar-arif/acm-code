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

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define pi acos(-1)

int main()
{
    int tst,len,s,i,ans;
    string a;
    sc1i(tst);
    getchar();
    while(tst--)
    {
        cin>>a;
        len = (int)a.size();
        s = 0;
        for(i = 0; i<len;i++)
        {
            s += a[i] - '0';
        }
        if(len > 1 and s <= 4){
            ans = 9 - s;
        }else{
            s %= 9;
            if(s > 4){
                ans = 9 - s;
            }else{
                ans = s;
            }
        }
        pf("%d\n",ans);
    }
    return 0;
}
