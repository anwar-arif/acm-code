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
#define mx            100001


struct seg
{
        ll sum,prop;
};

seg tree[mx * 3];

char a[mx];

void init(ll node,ll b,ll e)
{
        if(b == e)
        {
                tree[node].sum = a[b-1] - '0';
                return;
        }

        ll lft = node * 2;
        ll rt = lft + 1;
        ll mid = (b + e) / 2;

        init(lft , b , mid);
        init(rt , mid + 1, e);

        tree[node].sum = ( tree[lft].sum + tree[rt].sum ) ;
}

void update(ll node,ll b , ll e, ll i, ll j, ll x)
{
        if(b > j || e < i)return;
        if(b >= i && e <= j)
        {
                tree[node].prop += x;
                tree[node].sum += ( e - b + 1)*x;
                return;
        }
        ll lft = node * 2;
        ll rt = lft + 1;
        ll mid = (b + e) / 2;

        update(lft , b , mid , i , j , x);
        update(rt , mid + 1 , e , i , j , x);

        tree[node].sum = (tree[node].sum + tree[rt].sum + (e - b + 1) * tree[node].prop ) % 2;
}

ll query(ll node,ll b , ll e, ll i , ll carry)
{
        if(b > i || e < i)return 0;
        if(b >= i && e <= i)
        {
                return (tree[node].sum + carry * (e - b + 1) ) % 2;
        }

        ll lft = node * 2;
        ll rt = lft + 1;
        ll mid = (b + e) / 2;

        ll s1 = query(lft , b , mid , i , carry + tree[node].prop);
        ll s2 = query(rt , mid + 1 , e , i , carry + tree[node].prop);

        return (s1 + s2);
}

int main()
{
         ll tst,cas,len,q,i,j,ans;
         char ch;

         sc1ll(tst); getchar();

         for(cas = 1; cas <= tst; cas++)
         {
                 gets(a);  ll len = strlen(a);

                 memset(tree,0,sizeof(tree));

                 init(1 , 1 , len);

                 pf("Case %lld:\n",cas);

                 sc1ll(q);  getchar();

                 while(q--)
                 {
                         sc("%c",&ch);

                         if(ch == 'I')
                         {
                                 sc2ll(i,j); getchar();
                                 update(1 , 1 , len , i , j , 1);
                         }
                         else if(ch == 'Q')
                         {
                                 sc1ll(i);getchar();
                                 ans = query(1 , 1 , len , i , 0);
                                 pf("%lld\n",ans%2);
                         }
                 }
         }
         return 0;
}
