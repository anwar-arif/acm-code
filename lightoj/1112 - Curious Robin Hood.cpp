#include <bits/stdc++.h>
using namespace std;
#define pf            printf
#define sc            scanf
#define ll            long long
#define SIZ(a)        (int)a.size()
#define fil(a,x)      memset(a,x,sizeof(a))
#define pb            push_back
#define sc1i(a)       sc("%d",&a)
#define sc2i(a,b)     sc("%d%d",&a,&b)
#define sc3i(a,b,c)   sc("%d%d%d",&a,&b,&c)
#define mx            100001

int a[mx+5];
int tree[mx*3];

void init(int node,int b,int e)
{
        if(b == e)
        {
                tree[node] = a[b];
                return;
        }

        int lf = node * 2;
        int rt = lf + 1;
        int mid = (b + e) / 2;

        init(lf ,b ,mid);
        init(rt ,mid+1 ,e);

        tree[node] = tree[lf] + tree[rt];
}

void update(int node,int b,int e,int i,int newval)
{
        if(e < i || b > i)return;
        if(b >= i && e <= i)
        {
                tree[node] = newval;
                return;
        }

        int lft = node * 2;
        int rt = lft + 1;
        int mid = (b + e)/2;


        update(lft ,b ,mid, i, newval);
        update(rt, mid+1, e, i, newval);

        tree[node] = tree[lft] + tree[rt];

}

int total_money(int node,int b,int e,int I,int J)
{
        if(e < I || b > J)return 0;
        if(b >= I && e <= J)
        {
                return tree[node];
        }

        int lft = node * 2;
        int rt = lft + 1;
        int mid = (b + e) / 2;

        int s1 = total_money(lft ,b ,mid ,I ,J);
        int s2 = total_money(rt ,mid+1 ,e ,I ,J);

        return (s1 + s2);
}


int main()
{
        int tst,cas,n,q,typ,v,I,i,J,ind,j;
        sc1i(tst);
        for(cas = 1; cas <= tst;cas++)
        {
                fil(a,0);
                sc2i(n,q);
                for(i = 1; i <= n; i++)
                {
                        sc("%d",&a[i]);
                }

                init(1,1,n);

                pf("Case %d:\n",cas);

                while(q--)
                {
                        sc1i(typ);
                        if(typ == 1)
                        {
                                sc1i(ind);
                                pf("%d\n",a[ind+1]);
                                a[ind+1] = 0;
                                update(1,1,n,ind+1,0);
                        }
                        if(typ == 2)
                        {
                                sc2i(ind,v);
                                a[ind+1] = a[ind+1] + v;
                                int val = a[ind+1];
                                update(1,1,n,ind+1,val);
                        }
                        if(typ == 3)
                        {
                                sc2i(i,j);
                                int ans  = total_money(1,1,n,i+1,j+1);
                                pf("%d\n",ans);
                        }
                }
        }
        return 0;
}
