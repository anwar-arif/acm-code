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
#define dbl double

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
#define p_inf INT_MAX
#define n_inf INT_MIN
#define ppcnt(a) __builtin_popcount(a)
#define cnttz(a) __builtin_ctz(a)
#define cntlz(a) __builtin_clz(a)

#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)

#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};//4 side move
//int dy[]= {-1,1,0,0};//4 side move
//int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
//int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
//int dx[]={1,1,2,2,-1,-1,-2,-2};//knight move
//int dy[]={2,-2,1,-1,2,-2,1,-1};//knight move

template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}//N^P
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}//gcd(a,b)

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}


//void on(int &n,int pos){ n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = 200+20;

vector<int>g[N];
int cost[N][N],parent[N],n,d,b;

bool bfs(int s,int t)
{
    bool visited[N];
    mem(visited,false);

    visited[s] = true;
    parent[s] = s;

    queue<int>q;
    q.push(s);

    while(!q.empty()){

        int u = q.front(); q.pop();
        int len = SZ(g[u]);

        for(int i = 0 ; i< len;i++){
            int v = g[u][i];
            if(visited[v] == false and cost[u][v] > 0){
                visited[v] = true;
                parent[v] = u;
                if(v == t)return true;
                q.push(v);
            }
        }
    }
    return visited[t]==true;
}

int fordFulkerson(int s,int t)
{
    int mx_flow = 0;
    while(bfs(s,t)==true)
    {
        int path_flow = INT_MAX;
        for(int v = t;v != s;v = parent[v]){
            int u = parent[v];
            path_flow = min(path_flow,cost[u][v]);
        }
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            cost[u][v] -= path_flow;
            cost[v][u] += path_flow;
        }
        mx_flow += path_flow;
    }
    return mx_flow;
}

void reset()
{
    for(int i = 0; i < N-10;i++){
        g[i].clear();
        parent[i] = -1;
        for(int j = 0;j <N-10;j++){
            cost[i][j] = 0;
        }
    }
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas = 0;
      sc1i(tst);
      while(tst--)
      {
          reset();
          sc1i(n);
          int s = n+n+1;
          int t = s+1;
          for(int i = 1; i<=n;i++)
          {
              sc1i(cost[i][i+n]);
              g[i].pb(i+n);
              g[i+n].pb(i);
          }
          int e,u,v,w;
          sc1i(e);
          for(int i = 1; i<=e;i++)
          {
              sc3i(u,v,w);
              cost[u+n][v] = w;
              g[u+n].pb(v);
              g[v].pb(u+n);
          }
          sc2i(b,d);
          for(int i = 1; i<=b;i++)
          {
              sc1i(u);
              cost[s][u] = INT_MAX;
              g[s].pb(u);
              g[u].pb(s);
          }
          for(int i = 1; i<=d;i++)
          {
              sc1i(u);
              cost[u+n][t] = INT_MAX;
              g[u+n].pb(t);
              g[t].pb(u+n);
          }
          int ans = fordFulkerson(s,t);
          pf("Case %d: %d\n",++cas,ans);
      }
      return 0;
}
