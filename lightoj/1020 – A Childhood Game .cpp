#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define siz(a) (int)a.size()
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

int main()
{
    ll tst,cas,n;
    string s;
    sc1ll(tst);
    getchar();
    for(cas = 1; cas <= tst;cas++){
        cin>>n>>s;
        if(n % 3 == 0){
            pf("Case %lld: ",cas);
            cout<<s<<endl;
        }else if(n % 3 == 1){
            pf("Case %lld: ",cas);
            if(s == "Alice"){
                pf("Bob\n");
            }else{
               pf("Alice\n");
            }
        }
    }
    return 0;
}
