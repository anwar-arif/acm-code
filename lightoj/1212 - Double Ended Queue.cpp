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

#define pi acos(-1.0)

int main()
{
    int tst,cas,s,c,len,p,i,n;
    sc1i(tst);
    cas = 0;
    while(tst--)
    {
        sc2i(s,c);
        deque<int>dq;
        pf("Case %d:\n",++cas);
        for(i = 1; i <= c;i++)
        {
            string str;
            cin>>str;
            if(str == "pushLeft" or str == "pushRight")
            {
                sc1i(n);
                len = dq.size();
                if(len == s)
                {
                    pf("The queue is full\n");
                }
                else
                {
                    if(str == "pushLeft"){
                        dq.push_front(n);
                        pf("Pushed in left: %d\n",n);
                    }
                    else if(str == "pushRight")
                    {
                        dq.push_back(n);
                        pf("Pushed in right: %d\n",n);
                    }
                }
            }
            else
            {
                len = dq.size();
                if(str == "popLeft")
                {
                    if(len == 0){
                        pf("The queue is empty\n");
                    }
                    else
                    {
                        p = dq.front();
                        dq.pop_front();
                        pf("Popped from left: %d\n",p);
                    }
                }
                else if(str == "popRight")
                {
                    len = dq.size();
                    if(len == 0){
                        pf("The queue is empty\n");
                    }
                    else
                    {
                        p = dq.back();
                        dq.pop_back();
                        pf("Popped from right: %d\n",p);
                    }
                }
            }
        }
    }
    return 0;
}
