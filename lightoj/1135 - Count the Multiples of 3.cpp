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
#define p_inf 999999999
#define n_inf -999999999
#define SIZ 300000+5

#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
/*
int dx[]= {-1,-1,0,0,1,1};
int dy[]= {-1,0,-1,1,0,1};
int dx[]= {0,0,1,-1};//4 side move
int dy[]= {-1,1,0,0};//4 side move
int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
int dx[]={1,1,2,2,-1,-1,-2,-2};//knight move
int dy[]={2,-2,1,-1,2,-2,1,-1};//knight move
*/
template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//ll BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}

struct seg
{
    ll prop,a0,a1,a2;
};

seg tree[SIZ*3];

void build(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node].a0 = 1;
        tree[node].a1 = 0;
        tree[node].a2 = 0;
        tree[node].prop = 0;
        return;
    }
    ll lft,rt,mid;
    lft = node*2;
    rt = lft +1;
    mid = (b+e)/2;
    build(lft,b,mid);
    build(rt,mid+1,e);

    tree[node].a0 = tree[lft].a0+tree[rt].a0;
    tree[node].a1 = tree[lft].a1+tree[rt].a1;
    tree[node].a2 = tree[lft].a2+tree[rt].a2;
    tree[node].prop = 0;
}

void update(ll node,ll b,ll e,ll i,ll j)
{
    if(b>j or e < i)return;
    if(b>= i and e<=j)
    {
        tree[node].prop = (tree[node].prop+1)%3;
        ll x = tree[node].a0;
        tree[node].a0 = tree[node].a2;
        tree[node].a2 = tree[node].a1;
        tree[node].a1 = x;
        return;
    }
    ll lft,rt,mid;
    lft = node * 2;
    rt = lft+ 1;
    mid = (b+e)/2;
    update(lft,b,mid,i,j);
    update(rt,mid+1,e,i,j);

    tree[node].a0 = tree[lft].a0+tree[rt].a0;
    tree[node].a1 = tree[lft].a1+tree[rt].a1;
    tree[node].a2 = tree[lft].a2+tree[rt].a2;

    if(tree[node].prop == 1)
    {
        ll x = tree[node].a0;
        tree[node].a0 = tree[node].a2;
        tree[node].a2 = tree[node].a1;
        tree[node].a1 = x;
    }
    if(tree[node].prop == 2)
    {
        ll x = tree[node].a0;
        tree[node].a0 = tree[node].a1;
        tree[node].a1 = tree[node].a2;
        tree[node].a2 = x;
    }
    return;
}

ll query(ll node,ll b,ll e,ll i ,ll j,ll carry)
{
    if(b>j or e<i)return 0;
    if(b>=i and e<=j)
    {
        if(carry == 1)return tree[node].a2;
        else if(carry== 2)return tree[node].a1;
        else return tree[node].a0;
    }
    ll lft,rt,mid;
    lft = node*2;
    rt = lft+1;
    mid = (b+e)/2;

    ll p1 = query(lft,b,mid,i,j,(carry+tree[node].prop)%3);
    ll p2 = query(rt,mid+1,e,i,j,(carry+tree[node].prop)%3);

    return (p1+p2);
}

int main()
{
    ll tst,cas,n,q,t,a,b,ans;
    sc1ll(tst);
    cas = 0;
    while(tst--)
    {
        pf("Case %lld:\n",++cas);
        sc2ll(n,q);
        build(1,1,n);
        while(q--)
        {
            sc3ll(t,a,b);
            if(t == 1)
            {
                ans = query(1,1,n,a+1,b+1,0);
                pf("%lld\n",ans);
            }
            else
            {
                update(1,1,n,a+1,b+1);
            }
        }
    }
    return 0;
}
