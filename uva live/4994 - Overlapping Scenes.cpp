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

#define For(i,a,b) for(i=a;i<=b;i++)
#define pi acos(-1)

int main()
{
    int i,tst,n,cas,t,len,j,k,ans;
    sc1i(tst);
    cas = 0;

    while(tst--)
    {
        string s[100],s2;
        sc1i(n);
        for(i = 0; i<n; i++)
        {
            cin>>s[i];
        }

        for(i = 0; i<n;i++)
        {
            if(s[i].size()!= 0)
            {
                t = 0;
                len = s[i].size();
                for(j = 0;j <len;j++)
                {
                    s2 = "";
                    for(k = j; k < len;k++)
                    {
                        s2 += s[i][k];
                    }
                    //s2 = strcpy(s[i],j,len-1);
                    for(k = 0 ; k < n; k++)
                    {
                        if(k != i)
                        {
                            size_t f = s[k].find(s2);
                            if(f == 0)
                            {
                                s[i].erase(j,len);
                                s[i] += s[k];
                                s[k].clear();
                                t = 1;
                            }
                        }
                    }
                }
                if(t == 1)i = 0;
            }
        }
        ans = 0;
        for(i = 0 ; i < n;i++)
        {
            ans += s[i].size();
        }
        pf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
