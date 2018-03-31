#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <iterator>
#include <stack>
#include <queue>
#include <list>
#include <fstream>
#include <numeric>
#include <cstdlib>
#include <sstream>
using namespace std;

#define pf printf
#define sc scanf
#define LL long long
#define pb push_back

struct edge
{
        string s1,s2;
        int w;
        bool operator < (const edge& p)const
        {
                return w<p.w;
        }
};

vector<edge>g;
map<string,string>par;
int road;

string findpar(string r)
{
        return (par[r]==r)? r : findpar(par[r]);
}

int mst()
{
        int t=0,cnt=0,result=0,i;
        string u,v;

        sort(g.begin(),g.end());
        int node=par.size();

        for(i=0;i<(int)g.size();i++)
        {
                u=findpar(g[i].s1);
                v=findpar(g[i].s2);

                if(u!=v)
                {
                        par[u]=v;
                        ++cnt;
                        result+=g[i].w;
                        if(cnt==node-1){t=1;break;}
                }
        }
        if(t==1){return result;}
        return -1;
}

void init()
{
        par.clear();
        g.clear();
}

int main()
{
        int tst,cas,w,ans,i;
        string s1,s2;
        edge get;
        sc("%d\n",&tst);
        for(cas=1; cas<=tst; cas++)
        {
                sc("%d",&road);
                init();
                for(i=0;i<road;i++)
                {
                        cin>>s1>>s2>>w;

                        get.s1=s1; get.s2=s2; get.w=w;
                        g.pb(get);
                        par[s1]=s1;
                        par[s2]=s2;
                }
                ans=mst();
                if(ans==-1)
                {
                        pf("Case %d: Impossible\n",cas);
                }
                else
                {
                        pf("Case %d: %d\n",cas,ans);
                }
        }
        return 0;
}
