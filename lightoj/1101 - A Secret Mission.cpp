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

const int N = 50000+10;

struct edge{
    int u,v,w;
    bool operator < (const edge &p)const{
        return w < p.w;
    }
};

vector<edge>G;
vector<int>g[N],cost[N];
int pr[N],par[N][25],val[N][25];
int root,n;

int findpar(int r){
    return (pr[r] == r)?r : pr[r] = findpar(pr[r]);
}

void mst(){
    for(int i = 0 ;i <=n;i++){
        pr[i] = i;
    }
    sort(G.begin(),G.end());
    int cnt = 0;
    int s = 0;
    int len = SZ(G);
    for(int i = 0; i < len;i++){
        int u = findpar(G[i].u);
        int v = findpar(G[i].v);
        if(u != v){
            pr[u] = v;
            ++cnt;
            if(cnt == 1){
                root = G[i].u;
            }
            g[G[i].u].pb(G[i].v);
            g[G[i].v].pb(G[i].u);
            cost[G[i].u].pb(G[i].w);
            cost[G[i].v].pb(G[i].w);
            s += G[i].w;
            if(cnt == n-1)break;
        }
    }
}

int level[N],t[N];
bool visited[N];

void bfs(int s){
    mem(level,-1);
    level[s] = 0;
    mem(visited,false);
    visited[s] = true;

    queue<int>q;
    q.push(s);

    t[s] = s;
    val[s][0] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        int len = SZ(g[u]);
        for(int i = 0 ;i < len;i++){
            int v = g[u][i];
            if(visited[v] == false){
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
                t[v] = u;
                val[v][0] = cost[u][i];
            }
        }
    }
}

void ith_parent(){
    for(int i = 1 ;i <=n;i++){
        for(int j = 0; j < 22; j++){
            par[i][j] = -1;
        }
    }
    for(int i = 1; i <=n;i++){
        par[i][0] = t[i];
    }
    for(int j = 1; j < 22;j++){
        for(int i = 1; i<=n;i++){
            if(par[i][j-1] != -1){
                par[i][j] = par[ par[i][j-1] ][j - 1];
                int p = par[i][j - 1];
                val[i][j] = max( val[p][j-1] , val[i][j-1] );
            }
        }
    }
}

int query(int p,int q){
    if(level[p] < level[q]){
        int tmp; tmp = p; p = q; q = tmp;
    }
    int mx = 0;
    for(int i = 21; i >= 0; i--){
        if(level[p] - (1 << i) >= level[q]){
            mx = max(mx,val[p][i]);
            p = par[p][i];
        }
    }
    if(p == q)return mx;
    for(int i = 21; i>= 0; i--){
        if(par[p][i] != -1 and par[p][i] != par[q][i]){
            mx = max(mx,val[p][i]);
            mx = max(mx,val[q][i]);
            p = par[p][i];
            q = par[q][i];
        }
    }
    mx = max(mx,val[p][0]);
    mx = max(mx,val[q][0]);
    return mx;
}

void reset(){
    G.clear();
    for(int i = 0 ; i<=n;i++){
        g[i].clear();
        cost[i].clear();
    }
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas = 0,e,u,v,w,q,a,b;
      sc1i(tst);
      while(tst--)
      {
          sc2i(n,e);
          reset();

          for(int i = 0 ; i < e;i++){
              sc3i(u,v,w);
              edge get;
              get.u = u;get.v = v; get.w = w;
              G.pb(get);
          }

          mst();
          bfs(root);
          ith_parent();

          pf("Case %d:\n",++cas);

          sc1i(q);
          while(q--){
              sc2i(a,b);
              pf("%d\n",query(a,b));
          }
      }
      return 0;
}
