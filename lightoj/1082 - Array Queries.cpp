#include <bits/stdc++.h>
using namespace std;
#define pf            printf
#define sc            scanf
#define ll            long long
#define SIZ(a)        (int)a.size()
#define fill(a,x)     memset(a,x,sizeof(a))
#define pb            push_back
#define sc1i(a)       sc("%d",&a)
#define sc2i(a,b)     sc("%d%d",&a,&b)
#define sc3i(a,b,c)   sc("%d%d%d",&a,&b,&c)
#define mx            100004
#define inf           1e18


int a[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
        if(b == e)
        {
                tree[node] = a[b];
                return;
        }

        int left = node * 2;
        int right = left + 1;
        int mid = (b + e) / 2;

        init(left,b,mid);
        init(right,mid+1,e);

        tree[node] =min( tree[left] , tree[right] );
}

int query(int node,int b,int e,int I,int J)
{
        if(e < I || b > J )return inf;
        if(b >= I && e <= J )
        {
                return tree[node];
        }

        int left = node * 2;
        int right = left + 1;
        int mid = (b + e) / 2;

        int p = query(left,b,mid,I,J);

        int q = query(right,mid +1,e,I,J);

        return (min(p,q));
}


int main()
{
        int tst,cas,n,q,i,I,J;
        sc1i(tst);
        for(cas = 1; cas <= tst;cas++)
        {
                sc2i(n,q);

                for(i = 1; i <= n ;i++)
                {
                        sc("%d",&a[i]);
                }

                init(1,1,n);

                for(i = 1; i <= q; i++)
                {
                        sc2i(I,J);

                        if(i == 1){pf("Case %d:\n",cas);}

                        printf("%d\n",query(1,1,n,I,J));
                }
        }
        return 0;
}
