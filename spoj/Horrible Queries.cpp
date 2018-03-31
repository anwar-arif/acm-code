#include <bits/stdc++.h>
using namespace std;
#define pf            printf
#define sc            scanf
#define ll            long long int
#define SIZ(a)        (int)a.size()
#define fil(a,x)      memset(a,x,sizeof(a))
#define pb            push_back
#define sc1i(a)       sc("%d",&a)
#define sc2i(a,b)     sc("%d%d",&a,&b)
#define sc3i(a,b,c)   sc("%d%d%d",&a,&b,&c)
#define sc1ll(a)      sc("%lld",&a)
#define sc2ll(a,b)    sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c)  sc("%lld%lld%lld",&a,&b,&c)
#define mx            100005

struct seg
{
        ll sum,prop;
};

seg tree[mx*3];

void update(ll node,ll b,ll e,ll i,ll j, ll x)
{
        if(b > j || e < i)return;
        if(b >= i && e <= j)
        {
                tree[node].prop += x;
                tree[node].sum += ((e - b + 1) * x);
                return;
        }

        ll lft = node * 2;
        ll rt = lft + 1;
        ll mid = (b + e) / 2;

        update(lft , b , mid , i , j , x);
        update(rt , mid+1 , e, i , j , x);

        tree[node].sum = tree[lft].sum + tree[rt].sum + ((e - b + 1) * tree[node].prop);
}

ll query(ll node,ll b,ll e, ll i ,ll j,ll carry)
{
        if(b > j || e < i)return 0;
        if(b >= i && e <= j)
        {
                return tree[node].sum + carry * (e - b + 1);
        }

        ll lft = node * 2;
        ll rt = lft + 1;
        ll mid = (b + e) / 2;

        ll s1 = query(lft , b , mid , i , j ,carry + tree[node].prop);
        ll s2 = query(rt , mid+1 , e ,  i , j , carry + tree[node].prop);

        return (s1 + s2);
}

int main()
{
        ll tst,n,c,typ,ans,p,q,v;
        sc1ll(tst);
        while(tst--)
        {
                memset(tree, 0 , sizeof(tree));
                sc2ll(n,c);
                while(c--)
                {
                        sc1ll(typ);
                        if(typ == 0)
                        {
                                sc3ll(p,q,v);
                                update(1 , 1 , n , p , q , v);
                        }
                        else if(typ == 1)
                        {
                                sc2ll(p,q);
                                ll ans = query(1 , 1 , n , p , q , 0);
                                pf("%lld\n",ans);
                        }
                }
        }
        return 0;
}
