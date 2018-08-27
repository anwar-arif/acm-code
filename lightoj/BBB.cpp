#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
#include <fstream>
#include <climits>
#include <complex>
#include <new>
#include <memory>
#include <time.h>
//#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int
#define ull unsigned ll

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define pb push_back
#define pi acos(-1.0)
#define mem(a,x) memset(a,x,sizeof(a))
#define all(v) v.begin(),v.end()
#define SZ(a) (int)a.size()
#define MP make_pair
#define sqr(a) ((a)*(a))
#define ppcnt(a) __builtin_popcount(a)
#define cnttz(a) __builtin_ctz(a)
#define cntlz(a) __builtin_clz(a)

#define rep(i,k,n) for(__typeof(n)i = k ; i <= n; i++)
#define rrep(i,k,n) for(__typeof(k)i = k ; i >= n; i--)
#define show(a) cerr <<#a<< " = " << a << endl;

#define wait system("pause")
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {1,0-1,0};//4 side move
//int dy[]= {0,1,0,-1};//4 side move
//int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
//int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
//int dx[]={1,1,2,2,-1,-1,-2,-2};//knight move
//int dy[]={2,-2,1,-1,2,-2,1,-1};//knight move

template<class T> T power(T N,T P)
{
    return (P==0)?  1: N*power(N,P-1);   //N^P
}
template<class T> T gcd(T a,T b)
{
    if(b == 0)return a;    //gcd(a,b)
    return gcd(b,a%b);
}

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<< v <<" ";
        return *this;
    }
} dbg;
#define deb(args...) {dbg,args; cerr<<endl;}

void make_unique(vector<int> &a)
{
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}
ll bigmod(ll B,ll P,ll M)
{
    ll R=1;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

int on(int n,int pos)
{
    return n=n|(1<<pos);
}
int off(int n,int pos)
{
    return n = n & ~(1<<pos);
}
bool check(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

const int N = (int)1e5 + 10;

int main()
{

    int h, w, x, y;

    cin>>h>>w>>x>>y;

    int mat[h+x+5][w+y+5];

    for(int i=0; i<h+x; i++)
    {
        for(int j=0; j<w+y; j++)
        {
            cin>>mat[i][j];
        }
    }

    int ans[h+5][w+5];
    int cnt=h;

    int p=0, q=h-1;
    int p1=0, q1=h+x-1;

    while(1)
    {
        if(cnt)
        {
            for(int i=0; i<w; i++)
            {
                ans[p][i]=mat[p1][i];
            }
            p++;
            p1++;
            cnt--;
        }
        else break;

        if(cnt)
        {
            int kk=0;
            for(int i=y; i<w+y; i++)
            {
                ans[q][kk++]=mat[q1][i];
            }

            q--;
            q1--;
            cnt--;
        }
        else break;
    }

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }


    return 0;
}
