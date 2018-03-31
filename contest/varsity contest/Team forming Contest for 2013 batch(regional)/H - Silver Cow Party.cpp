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
#define SIZ 1000+5
#define ppcnt(a) __builtin_popcount(a)

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
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}//N^P
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}//gcd(a,b)

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//ll BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}

struct node
{
    int u,w;
    bool operator < (const node &p)const
    {
        return w>p.w;
    }
};

int n;

void dij(int s,vector<vector<int> >& gr,vector<vector<int> >&cost,int d[])
{
    priority_queue<node>q;
    node e;
    e.u = s;e.w = 0;
    mem(d,p_inf);
    d[s] = 0;
    while(!q.empty())
    {
        node e = q.top();q.pop();
        int u;
        u = e.u;
        int len = (int)gr[u].size();
        for(int i = 0 ; i < len;i++)
        {
            int v;
            v = gr[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v] = d[u]+cost[u][i];
                e.u = v;e.w = d[v];
                q.push(e);
            }
        }
    }
//    for(int i = 1; i<= n;i++){
//        pf("%d ",d[i]);
//    }pf("\n");
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int m,trgt,u,v,w;
      sc3i(n,m,trgt);
      vector<vector<int> >g(SIZ),rg(SIZ);
      vector<vector<int> >cost(SIZ),rcost(SIZ);
      for(int i = 0 ; i < m;i++)
      {
          sc3i(u,v,w);
          g[u].pb(v);
          rg[v].pb(u);
          cost[u].pb(w);
          rcost[v].pb(w);
      }
      int d1[SIZ],d2[SIZ];
      mem(d1,p_inf);mem(d2,p_inf);
      dij(trgt,g,cost,d1);
      dij(trgt,rg,rcost,d2);
      int mx = 0;
      for(int i = 1; i<= n;i++)
      {
          pf("%d %d\n",d1[i],d2[i]);
          if(d1[i]!= p_inf and d2[i] != p_inf)
          {
              mx = max(mx,d1[i]+d2[i]);
          }
      }
      pf("%d\n",mx);
      return 0;
}
