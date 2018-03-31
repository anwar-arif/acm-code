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
    int i,c,mxlen,len[200],j;
    char a[200][200];
    c = -1;mxlen = -1;
    while(gets(a[++c])){
        len[c] = strlen(a[c]);
        mxlen = max(mxlen,len[c]);
    }
    for(i = 0 ; i < mxlen;i++){
        for(j = c;j>=0;j--){
            if(i>=len[j]){
                pf(" ");
            }
            else{
                pf("%c",a[j][i]);
            }
        }
        pf("\n");
    }
    return 0;
}
