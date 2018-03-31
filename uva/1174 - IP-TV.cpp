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
#define pi acos(-1)

struct edge
{
        int u,v,w;
        bool operator < (const edge& p)const
        {
                return w < p.w;
        }
};

vector<edge>g;
int par[2005];

int findpar(int r)
{
        return (par[r] == r)?r:findpar(par[r]);
}

int mst(int n)
{
        sort(g.begin(),g.end());
        int len,cnt,s,u,v,i;
        for(i = 0; i <= n;i++)par[i] = i;
        len =(int)g.size();
        cnt = 0;s =0;
        for(i = 0; i < len;i++){
                u = findpar(g[i].u);
                v = findpar(g[i].v);
                if(u != v){
                        par[u] = v;
                        s += g[i].w;
                        ++cnt;
                        if(cnt == n-1)break;
                }
        }
        return s;
}

int main()
{
        int tst,cas,e,k,i,ans,x,n;
        string s2,s1;
        sc1i(tst);
        for(cas = 0 ; cas < tst;cas++){
                        if(cas)pf("\n");
                sc2i(n,e);getchar();k = 0;
                g.clear();
                map<string,int>m;
                for(i = 1;i <= e;i++){
                        cin>>s1>>s2>>x;
                        if(m[s1] == 0){
                                m[s1] = ++k;
                        }
                        if(m[s2] == 0){
                                m[s2] = ++k;
                        }
                        edge get;
                        get.u = m[s1];
                        get.v = m[s2];
                        get.w = x;
                        g.push_back(get);
                }
                ans = mst(n);
                pf("%d\n",ans);

        }
        return 0;
}
