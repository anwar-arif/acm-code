#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define ll long long int
#define pi acos(-1.0)

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define MX 100005

struct seg
{
    int mn,mx;
};

seg tree[MX*4];
int a[MX];

void build(int node,int b,int e)
{
    if(b == e)
    {
        tree[node].mx = a[b];
        tree[node].mn = a[b];
        return;
    }
    int lft,rt,mid;
    lft = node*2;
    rt = lft +1;
    mid = (b+e) / 2;

    build(lft,b,mid);
    build(rt,mid+1,e);

    tree[node].mx = max(tree[lft].mx,tree[rt].mx);
    tree[node].mn = min(tree[lft].mn,tree[rt].mn);
}

pair<int,int> query(int node,int b,int e,int i,int j)
{
    if(b > j or e < i)
    {
        pair<int,int>p;
        p.first = -999999999;
        p.second = 999999999;
        return p;
    }
    if(b >= i and e <= j)
    {
        pair<int,int>a;
        a.first = tree[node].mx;
        a.second = tree[node].mn;
        return a;
    }

    int lft,rt,mid;
    lft = node*2;
    rt = lft +1;
    mid = (b+e) / 2;

    pair<int,int>d; d = query(lft,b,mid,i,j);
    pair<int,int>c; c = query(rt,mid+1,e,i,j);

    pair<int,int> res;
    res.first = max(d.first,c.first);
    res.second = min(d.second,c.second);
    return res;

}

int main()
{
    int tst,cas,n,d,mx,mn,ans,i;
    sc1i(tst);
    cas = 0;
    while(tst--)
    {
        sc2i(n,d);
        for(i = 1; i<= n;i++)
        {
            sc1i(a[i]);
        }
        build(1,1,n);
        ans = -999999999;
        for(i = 1; i<=n-d+1;i++)
        {
            pair<int,int>e;
            e = query(1,1,n,i,i+d-1);
            mx = e.first;
            mn = e.second;
            ans = max(ans,mx-mn);
        }
        pf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

