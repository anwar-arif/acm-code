#include<bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf

#define ll long long int
#define pb push_back
#define SZ(a) (int)a.size()
#define mem(a,x) memset(a,x,sizeof(a))

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define SIZ 40+5

long long int dp[2][2][SIZ][SIZ];

vector<ll>inp;

int len;
///count the numbers with 0 within a range

ll rec( bool isStart, bool cmp, int pos, int zeros )
{
    if( pos >= len ) return zeros;

    ll &ret = dp[isStart][cmp][pos][zeros];

    if( ret != -1 )return ret;

    int limt, i, tmp;

    limt = cmp ? inp[pos] : 9;///cmp = 1 if it was full fil previous digit

    ret = 0;

    if( !isStart )
    {
        for( i = 0; i <= limt; i++ )
        {
            ret += rec( isStart, ( cmp and i == limt ), pos+1, zeros +(i==0) );
        }
    }
    else
    {
        for( i = 1; i<=limt; i++ )
        {
            ret += rec( 0, ( cmp and i == limt ), pos+1, zeros +(i==0) );
        }

        ret += rec( 1, 0, pos+1, 0 );
    }
    return ret;
}

ll cal(ll x)
{
    if(x<0)return 0;

    if(x<=9)return 1;

    inp.clear();

    while(x)
    {
        inp.pb(x%10);
        x /= 10;
    }

    reverse(inp.begin(),inp.end());

    len = SZ(inp);

    mem(dp,-1);

    return rec( 1, 1, 0, 0) + 1;
}

int main()
{
      int tst,cas = 0 ;

      ll a,b;

      sc1i(tst);

      while(tst--)
      {
        sc2ll(a,b);

        ll ans = cal(b) - cal(a-1);

        pf("Case %d: %lld\n",++cas,ans);
      }
      return 0;
}
