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
#define For(i,a,b) for(i=a;i<=b;i++)
#define pi acos(-1)

int main()
{
    int cas = 0;
    string str;
    while((cin>>str)){
        if(str == "#")return 0;
        if(str == "HELLO")pf("Case %d: ENGLISH",++cas);
        else if(str == "HOLA")pf("Case %d: SPANISH",++cas);
        else if(str == "HALLO")pf("Case %d: GERMAN",++cas);
        else if(str == "BONJOUR")pf("Case %d: FRENCH",++cas);
        else if(str =="CIAO")pf("Case %d: ITALIAN",++cas);
        else if(str == "ZDRAVSTVUJTE")pf("Case %d: RUSSIAN",++cas);
        else {pf("Case %d: UNKNOWN",++cas);}
        pf("\n");
    }
}
