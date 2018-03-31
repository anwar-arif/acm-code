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
#define SIZ 30000

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

vector<int>g[SIZ+5],cost[SIZ+5];
bool visited[SIZ+5];
int level[SIZ+5];

void reset(int n)
{
    for(int i = 0 ;i <= n;i++)
    {
        g[i].clear();
        cost[i].clear();
        visited[i] = false;
        level[i] = 0;
    }
}

int source,mx;

int bfs(int s,int dst)
{
    int u,v,len,i,node;
    queue<int>q;
    q.push(s);
    node = -1;
    level[s] = 0;
    while(!q.empty())
    {
        u = q.front();q.pop();
        len = (int)g[u].size();
        for(i = 0 ;i  < len;i++)
        {
            v = g[u][i];
            if(visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
                level[v] = level[u] + cost[u][i];
                if(level[v] > mx)
                {
                    mx = level[v];
                    node = v;
                }
            }
        }
    }
    return node;
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas,u,v,w,i,n,x,y;
      sc1i(tst);
      cas = 0 ;
      while(tst--)
      {
          sc1i(n);
          reset(n);
          for(i = 1; i< n;i++)
          {
              sc3i(u,v,w);
              g[u].pb(v);
              g[v].pb(u);
              cost[u].pb(w);
              cost[v].pb(w);
              if(i == 1)source = u;
          }
          visited[source] = true;
          mx = n_inf;
          x = bfs(source,0);
          mx = n_inf;
          mem(visited,false);
          visited[x] = true;
          y = bfs(x,0);
          pf("Case %d: %d\n",++cas,mx);
      }
      return 0;
}
